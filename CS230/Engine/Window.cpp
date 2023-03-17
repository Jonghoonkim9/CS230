#include <doodle/window.hpp>
#include "Window.h"

void CS230::Window::Start(std::string title) {
    doodle::create_window(title, default_width, default_height);
}


void CS230::Window::Update() {
    doodle::update_window();
}
