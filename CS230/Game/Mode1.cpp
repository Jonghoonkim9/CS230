#include "../Engine/Engine.h"
#include "States.h"
#include "Mode1.h"
#include "doodle/doodle.hpp"

using namespace doodle;

Mode1::Mode1() {

}

void Mode1::Load() {
}

void Mode1::Update() {
    if (KeyIsPressed && Key == KeyboardButtons::NumPad_1) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    }
    if (KeyIsPressed && Key == KeyboardButtons::_1) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode2));
    }
}

void Mode1::Unload() {

}