#pragma once
#include <string>

namespace CS230 {
    class Window {
    public:
        void Start(std::string title);
        void Update();
    private:
        static constexpr int default_width = 800;
        static constexpr int default_height = 600;
    };
}