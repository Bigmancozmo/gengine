#include "ProgramRunner.hpp"

namespace gengine {
	ProgramRunner::ProgramRunner(const std::string& executablePath) : executablePath(executablePath) {}

	int ProgramRunner::run() {
		int returnValue = std::system(executablePath.c_str());
		return returnValue;
	}
}