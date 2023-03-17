#pragma once
#include "Window.h"
#include "Logger.h"
#include "GameStateManager.h"

class Engine {
public:
    static Engine& Instance() {
        static Engine instance;
        return instance;
    }
    static CS230::Logger& GetLogger() {
        return Instance().logger;
    }
    static CS230::Window& GetWindow() {
        return Instance().window;
    }
    static CS230::GameStateManager& GetGameStateManager() {
        return Instance().gamestatemanager;
    }

    void Start(std::string window_title);
    void Stop();
    void Update();
    bool HasGameEnded();
private:
    Engine();
    ~Engine();

    CS230::Logger logger;
    CS230::Window window;
    CS230::GameStateManager gamestatemanager;
};