#include "Engine/Engine.h"
#include "Game/Splash.h"
#include "Game/Mode1.h"
#include "Game/Mode2.h"

int main() {
    Engine& engine = Engine::Instance();
    engine.Start("Assignment 1 - Jonghoon Kim");

    Splash splash;
    engine.GetGameStateManager().AddGameState(splash);
    Mode1 mode1;
    engine.GetGameStateManager().AddGameState(mode1);
    Mode2 mode2;
    engine.GetGameStateManager().AddGameState(mode2);

    while (engine.HasGameEnded() == false) {
        engine.Update();
    }
    engine.Stop();

    return 0;
}
