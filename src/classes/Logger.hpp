#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>

namespace gengine {
	enum LogType {
		DEFAULT,
		INFO,
		WARN,
		ERROR
	};

	class Logger {
		private:
			std::string loggerName;
		public:
			Logger(std::string loggerName);
			void log(LogType type, std::string message);
			void log(std::string message);
	};
}

#endif // LOGGER_HPP