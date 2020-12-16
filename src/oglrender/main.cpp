#include <iostream>
#include <stdexcept>

#include "window.h"
#include "app.h"

int main() {
    Window::Settings settings;
    settings.width = 1280;
    settings.height = 720;
    Window window(settings);

    App app(window);

    try {
        app.run();
    } catch (std::exception e) {
        std::cout << "Error: " << e.what() << std::endl;
        exit(-1);
    }

    exit(0);
}