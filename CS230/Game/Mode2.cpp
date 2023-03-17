#include "../Engine/Engine.h"
#include "Mode2.h"
#include "doodle/doodle.hpp"

using namespace doodle;


Mode2::Mode2() {

}

void Mode2::Load() {

}

void Mode2::Update() {
    if (KeyIsPressed && Key == KeyboardButtons::NumPad_2) {
        Engine::GetGameStateManager().ClearNextGameState();
    }
    if (KeyIsPressed && Key == KeyboardButtons::_2) {
        Engine::GetGameStateManager().ClearNextGameState();
    }
}

void Mode2::Unload() {

}