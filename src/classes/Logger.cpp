#include "Logger.hpp"

gengine::Logger::Logger(std::string loggerName)
{
    this->loggerName = loggerName;
    log(INFO, "Initialized logger");
}

void gengine::Logger::log(LogType type, std::string message)
{
    switch (type) {
        case DEFAULT:
            std::cout << "\033[38;2;137;137;137m[" << this->loggerName << "] " << message << "\033[0m\n";
            break;
        case WARN:
            std::cout << "\033[33m[" << this->loggerName << "][WARN] " << message << "\033[0m\n";
            break;
        case ERROR:
            std::cout << "\033[31m[" << this->loggerName << "][ERROR] " << message << "\033[0m\n";
            break;
        case INFO:
            std::cout << "\033[97m[" << this->loggerName << "][INFO] " << message << "\033[0m\n";
            break;
    };
}

void gengine::Logger::log(std::string message)
{
    log(DEFAULT, message);
}
