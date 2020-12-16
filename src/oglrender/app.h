#ifndef __APP_OGLRENDER_H
#define __APP_OGLRENDER_H

#include "window.h"

class App {
public:
    explicit App(Window&);
    ~App();
    void run();
private:
    Window& window;

    void process_input();

    void update();
    void draw();
};

#endif