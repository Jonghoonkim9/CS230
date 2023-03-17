#pragma once
#include <string>
#include <fstream>

namespace CS230 {
    class Logger {
    public:
        enum class Severity {
            Verbose,  //Minor messages
            Debug,    //Only used while actively debugging
            Event,    //General event, like key press or state change
            Error     //Errors, such as file load errors
        };
        Logger(Severity severity, bool use_console);
        ~Logger();
        void LogError(std::string text) {
            log(Severity::Error, text);
        }
        void LogEvent(std::string text) {
            log(Severity::Event, text);
        }
        void LogDebug(std::string text) {
            log(Severity::Debug, text);
        }
        void LogVerbose(std::string text) {
            log(Severity::Verbose, text);
        }
    private:
        Severity min_level;
        std::ofstream out_stream;
        void log(Severity severity, std::string message);
    };
}