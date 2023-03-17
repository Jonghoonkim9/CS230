#pragma once
#include "Engine.h"

Engine::Engine() :
#ifdef _DEBUG				
    logger(CS230::Logger::Severity::Debug, true)
#else 						
    logger(CS230::Logger::Severity::Event, false)
#endif
{ }

Engine::~Engine() {}

void Engine::Start(std::string window_title) {
    logger.LogEvent("Engine Started");
    window.Start(window_title);
    //Start other services
}

void Engine::Stop() {
    //Stop all services
    logger.LogEvent("Engine Stopped");
}

void Engine::Update() {
    logger.LogVerbose("Engine Update");
    gamestatemanager.Update();
    window.Update();
    //Update other services
}

bool Engine::HasGameEnded() {
    return GetGameStateManager().HasGameEnded();
}