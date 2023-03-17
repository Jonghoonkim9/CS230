#include <iostream>
#include "Logger.h"

CS230::Logger::Logger(Logger::Severity severity, bool use_console) : min_level(severity), out_stream("Trace.log") {
    if (use_console == true) {
        out_stream.set_rdbuf(std::cout.rdbuf());
    }
}

CS230::Logger::~Logger() {
    out_stream.flush();
    out_stream.close();
}

void CS230::Logger::log(CS230::Logger::Severity severity, std::string message) {
    std::string severity_text;
    switch (severity) {
    case Severity::Verbose:
        severity_text = "Verbose";
        break;
    case Severity::Debug:
        severity_text = "Debug";
        break;
    case Severity::Event:
        severity_text = "Event";
        break;
    case Severity::Error:
        severity_text = "Error";
        break;
    default:
        return;
    }
    if (static_cast<int>(severity) >= static_cast<int>(min_level)) {
        out_stream << severity_text << "\t" << message << std::endl;
    }
}
