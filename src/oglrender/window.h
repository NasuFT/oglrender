#ifndef __OGLRENDER_WINDOW_H
#define __OGLRENDER_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define KEY_ESCAPE GLFW_KEY_ESCAPE

class Window{
public:
    struct Settings {
        int width = 800;
        int height = 600;
        const char* title = "OGL Render";
    };

    explicit Window(Window::Settings&);
    ~Window();

    void swap_buffers();
    void poll_events();

    bool should_close();
    void set_close();

    bool is_key_down(int);
private:
    GLFWwindow* window;

    void init_window(Window::Settings&);
    static void framebuffer_size_callback(GLFWwindow*, int, int);
};

#endif