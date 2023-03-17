#pragma once
#include "../Engine/GameState.h"

class Mode1 : public CS230::GameState {
public:
    Mode1();
    void Load() override;
    void Update() override;
    void Unload() override;

    std::string GetName() override { return "Mode1"; }
};
