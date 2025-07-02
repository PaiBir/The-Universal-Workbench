#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <cerrno>

namespace Interp {
	void readScriptFile(std::string filename);
	void readScriptFile(std::string filename, std::fstream& openfile);
};