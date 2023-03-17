#include "../Engine/Engine.h"
#include "States.h"
#include "Splash.h"


Splash::Splash() {

}

void Splash::Load() {
    counter = 0;
}

void Splash::Update() {
    Engine::GetLogger().LogDebug(std::to_string(counter));
    if (counter >= 5) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Mode1));
    }
    counter++;
}

void Splash::Unload() {

}
