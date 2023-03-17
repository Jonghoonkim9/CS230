#pragma once
#include <string>

namespace CS230 {
    class GameState {
    public:
        virtual void Load() = 0;
        virtual void Update() = 0;
        virtual void Unload() = 0;
        virtual std::string GetName() = 0;
    private:
    };
}