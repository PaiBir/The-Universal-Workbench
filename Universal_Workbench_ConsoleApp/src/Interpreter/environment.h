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
		unsigned int lineVal;
		std::string filepath;
	public:
		std::string vartoken;
		enum vartype typing;

		interpvar(std::string vt, enum vartype typing);
	};
	class environment
	{
	public:
	};
}

