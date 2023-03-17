#pragma once
#include "GameState.h"
#include <vector>

namespace CS230 {
    class GameStateManager {
    public:
        GameStateManager();

        void Update();

        void AddGameState(GameState& gamestate);
        void SetNextGameState(int index);
        void ClearNextGameState();
        void ReloadGameState();
        bool HasGameEnded() { return status == Status::EXIT; }
    private:
        enum class Status {
            STARTING,
            LOADING,
            UPDATING,
            UNLOADING,
            STOPPING,
            EXIT
        };

        Status status = Status::STARTING;
        std::vector<GameState*> gamestates;
        GameState* current_gamestate = nullptr;
        GameState* next_gamestate = nullptr;
    };
}
