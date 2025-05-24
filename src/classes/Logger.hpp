#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include "../dll.h"

namespace gengine {
	enum GENGINE_API LogType {
		DEFAULT,
		INFO,
		WARN,
		ERROR
	};

	class GENGINE_API Logger {
		private:
			std::string loggerName;
		public:
			Logger(std::string loggerName);
			void log(LogType type, std::string message);
			void log(int type, std::string message);
			void log(std::string message);
	};
}

#endif // LOGGER_HPP