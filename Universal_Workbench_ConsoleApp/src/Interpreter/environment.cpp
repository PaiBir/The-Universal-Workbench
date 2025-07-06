#include "environment.h"

interp::interpvar::interpvar(std::string vt, enum vartype type, int pos, std::string fp) : vartoken(vt) {
	posInFile = pos;
	typing = type;
	filepath = fp;
}

template <typename T> void interp::interpvar::getvalue(std::vector<T>& assignment, std::fstream& file, std::string currentFile)
{
	std::string varline;
	if (currentFile == filepath) {
		file.seekg(posInFile);
		std::getline(file, varline);
	}
	else {
		std::ifstream quickread;
		quickread.open(filepath);
		quickread.seekg(posInFile);
		std::getline(quickread, varline);
	}

	switch (typing)
	{
	case interp::INT:
		break;
	case interp::DOUBLE:
		break;
	case interp::STRING:
		assignment.clear();
		assignment.push_back();
	case interp::FILEPATH:
		break;
	case interp::ENVIRONMENT_SPECIFIC:
		break;
	case interp::ARRAY:
		break;
	default:
		break;
	}
	return 1;
}
