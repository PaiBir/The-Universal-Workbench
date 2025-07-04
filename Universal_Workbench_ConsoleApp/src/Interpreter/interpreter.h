#pragma once
#include "../includes.h"

namespace Interp {
	void readScriptFile(std::string filename);
	void readScriptFile(std::string filename, std::fstream& openfile);
};