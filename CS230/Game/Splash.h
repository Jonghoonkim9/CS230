#pragma once
#include "../Engine/GameState.h"

class Splash : public CS230::GameState {
public:
    Splash();
    void Load() override;
    void Update() override;
    void Unload() override;

    std::string GetName() override { return "Splash"; }
public:
    int counter = 0;
};
