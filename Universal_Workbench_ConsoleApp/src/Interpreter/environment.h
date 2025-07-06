#pragma once
#include "../includes.h"

namespace interp {
	enum vartype {
		INT,
		DOUBLE,
		STRING,
		FILEPATH,
		ENVIRONMENT_SPECIFIC,
		ARRAY
	};
	class interpvar {
	private:
		int posInFile;
		std::string filepath;
		enum vartype typing;

	public:
		const std::string vartoken;

		interpvar(std::string vt, enum vartype type, int pos, std::string fp);

		template <typename T> void getvalue(std::vector<T>& assignment, std::fstream& file, std::string currentFile)
	};
	class environment
	{
	public:
	};
}

