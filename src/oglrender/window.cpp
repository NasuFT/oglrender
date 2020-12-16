#include <stdexcept>

#include "window.h"

Window::Window(Window::Settings& settings) {
    init_window(settings);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::init_window(Window::Settings& settings) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(settings.width, settings.height, settings.title, nullptr, nullptr);
    if(window == nullptr)
        throw std::exception("Failed to create a GLFW window!");
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::exception("Failed to initialize GLAD!");

    glViewport(0, 0, settings.width, settings.height);    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Window::swap_buffers() {
    glfwSwapBuffers(window);
}

void Window::poll_events() {
    glfwPollEvents();
}

bool Window::should_close() {
    return glfwWindowShouldClose(window);
}

void Window::set_close() {
    glfwSetWindowShouldClose(window, true);
}

bool Window::is_key_down(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  