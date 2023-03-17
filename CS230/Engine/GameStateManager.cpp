#include "GameStateManager.h"
#include "Engine.h"

CS230::GameStateManager::GameStateManager() { }

void CS230::GameStateManager::AddGameState(GameState& gamestate) {
    gamestates.push_back(&gamestate);
}

void CS230::GameStateManager::SetNextGameState(int index) {
    next_gamestate = gamestates[index];
}

void CS230::GameStateManager::ReloadGameState() {
    status = Status::UNLOADING;
}

void CS230::GameStateManager::ClearNextGameState() {
    next_gamestate = nullptr;
    status = Status::EXIT;
}

void CS230::GameStateManager::Update() {
    switch (status) {
    case Status::STARTING:
        next_gamestate = gamestates[0];
        status = Status::LOADING;
        if(gamestates.size() == 0) {
            status = Status::STOPPING;
        }
        break;
    case Status::LOADING:
        current_gamestate = next_gamestate;
        Engine::GetLogger().LogEvent("Load " + current_gamestate->GetName());
        current_gamestate->Load();
        Engine::GetLogger().LogEvent("Load Complete");
        status = Status::UPDATING;
        break;
    case Status::UPDATING:
        if (current_gamestate != next_gamestate) {
            status = Status::UNLOADING;
        }
        else {
            current_gamestate->Update();
        }
        break;
    case Status::UNLOADING:
        Engine::GetLogger().LogEvent("Unload " + current_gamestate->GetName());
        current_gamestate->Unload();
        Engine::GetLogger().LogEvent("Unload Complete");
        if (next_gamestate) {
            status = Status::LOADING;
        }
        else {
            status = Status::STOPPING;
        }
        break;
    case Status::STOPPING:
        status = Status::EXIT;
        break;
    case Status::EXIT:
        break;
    }
}
