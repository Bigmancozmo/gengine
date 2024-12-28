#ifndef PROGRAMRUNNER_HPP
#define PROGRAMRUNNER_HPP

#include <string>

namespace gengine {
	class ProgramRunner {
		public:
			ProgramRunner(const std::string& executablePath);
			int run();
		private:
			std::string executablePath;
	};
}

#endif // PROGRAMRUNNER_HPP