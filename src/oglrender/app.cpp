#include "app.h"

App::App(Window& window) : window(window) {}

App::~App() {}

void App::run() {
    while(!window.should_close()) {
        process_input();

        update();
        draw();

        window.swap_buffers();
        window.poll_events();
    }
}

void App::process_input() {
    if(window.is_key_down(KEY_ESCAPE))
        window.set_close();
}

void App::update() {

}

void App::draw() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}