#pragma once
#include "../Engine/GameState.h"

class Mode2 : public CS230::GameState {
public:
    Mode2();
    void Load() override;
    void Update() override;
    void Unload() override;

    std::string GetName() override { return "Mode2"; }
};