#include "interpreter.h"

namespace Interp {
	void readScriptFile(std::string filename) {
		std::string ABSPATH;
		std::string ScriptName;
		const std::string del = "\\"; //To focus out the name of the file
		int start = -1;
		int end = -1 * del.size();
		std::vector<std::string> returner = {};
		//Basically, keep going to the last one, to chop off the file name and have a remaining directory
		while (end != -1 || start == -1) {
			start = end + del.size();
			end = filename.find(del, start);
			ScriptName = (filename.substr(start, end - start));
		}
		ABSPATH = filename;
		ABSPATH.erase(start);
		std::ifstream f(filename);

		if (!f.is_open()) {
			std::cerr << "Error opening the file!";
			return;
		}

		//Space for internal script variables
		std::fstream currentLog;
		std::string logpath;

		//File Reader
		std::string line;
		while (std::getline(f, line)) {
			//std::cout << line << std::endl;
			const std::string commentMarker = "#"; //This should not be changed
			//Chop off everything after the first comment marker on that line
			int lstart, lend = -1 * commentMarker.size();
			lstart = lend + commentMarker.size();
			lend = line.find(commentMarker, lstart);
			std::string command = (line.substr(lstart, lend - lstart));


			//std::cout << command << std::endl;

			//command recognition will be a series of if statements until I figure out a better way. Each line only gets 1 command
			//first, the command is broken down into the action, and context (action being "log" or "print", context being the data informing the action)

			//while it is bad form, everything after the EndContext character ")" is not currently used in commands. So the commend character isn't necessary
			const std::string EndContext = ")";
			//everything before the StartContext character is read as the action. This includes spaces, and is case sensitive
			const std::string StartContext = "(";
			std::string action;
			std::string context;
			int actionstart, actionend = -1 * StartContext.size();
			actionstart = actionend + commentMarker.size();
			actionend = line.find(StartContext, actionstart);
			action = (line.substr(actionstart, actionend - actionstart));
			std::string remainder = command;
			remainder.erase(0, actionend+1);

			//now isolate the context
			int contextstart, contextend = -1 * EndContext.size();
			contextstart = contextend + commentMarker.size();
			contextend = remainder.find(EndContext, contextstart);
			context = (remainder.substr(contextstart, contextend - contextstart));
			
			//Storage for strings "n(ew) string cont(ext)"
			std::string nstringcont = "";

			if (context.size() >= 3) {
				if ((context.find('"')) != std::string::npos) {
					nstringcont = context.substr(1, context.size()-2);
				}
				else {
					nstringcont = context;
				}
			}
			
			//if trees
			if (action == "log") { //TODO: implement backmoving in file tree
				if (currentLog.is_open()) {
					time_t timestamp;
					char str[26];
					time(&timestamp);
					ctime_s(str, sizeof str, &timestamp);
					currentLog << "\nClosing log at " << str << std::endl;
					currentLog.close();
				}
				currentLog.open(ABSPATH + nstringcont);

				if (currentLog.is_open()) {
					time_t timestamp;
					char str[26];
					time(&timestamp);
					ctime_s(str, sizeof str, &timestamp);
					currentLog << "Created new log at " << str << std::endl;
					logpath = ABSPATH + nstringcont;
				}
				else {
					char errmsg[94];
					strerror_s(errmsg, sizeof(errmsg), errno);

					std::cout << "ERROR! CANNOT OPEN LOG FILE!" << "\n" << errmsg << "\n\n" << (ABSPATH+ nstringcont) << "\n" << std::endl;
				}
			}
			else if (action == "print") {
				currentLog << ScriptName << ": " << nstringcont << std::endl;
				std::cout << "printing!" << std::endl;
			}
			else if (action == "open") {
				readScriptFile(ABSPATH + nstringcont, currentLog);
				if (!currentLog.is_open()) {
					currentLog.open(logpath, std::fstream::app);
				}
				std::cout << "opening!" << std::endl;
			}
			else if (action == "closelog") {
				time_t timestamp;
				char str[26];
				time(&timestamp);
				ctime_s(str, sizeof str, &timestamp);
				currentLog << "\nClosing log at " << str << std::endl;
				currentLog.close();
			}
			else {
				std::cout << "invalid command!" << std::endl;
			}
		}

		f.close();
	}

	void readScriptFile(std::string filename, std::fstream& openfile) {
		std::string ABSPATH;
		std::string ScriptName;
		const std::string del = "\\"; //To focus out the name of the file
		int start = -1;
		int end = -1 * del.size();
		std::vector<std::string> returner = {};
		//Basically, keep going to the last one, to chop off the file name and have a remaining directory
		while (end != -1 || start == -1) {
			start = end + del.size();
			end = filename.find(del, start);
			ScriptName = (filename.substr(start, end - start));
		}
		ABSPATH = filename;
		ABSPATH.erase(start);
		std::ifstream f(filename);

		if (!f.is_open()) {
			std::cerr << "Error opening the file!";
			return;
		}

		//Space for internal script variables
		std::fstream currentLog;


		//File Reader
		std::string line;
		while (std::getline(f, line)) {
			//std::cout << line << std::endl;
			const std::string commentMarker = "#"; //This should not be changed
			//Chop off everything after the first comment marker on that line
			int lstart, lend = -1 * commentMarker.size();
			lstart = lend + commentMarker.size();
			lend = line.find(commentMarker, lstart);
			std::string command = (line.substr(lstart, lend - lstart));


			//std::cout << command << std::endl;

			//command recognition will be a series of if statements until I figure out a better way. Each line only gets 1 command
			//first, the command is broken down into the action, and context (action being "log" or "print", context being the data informing the action)

			//while it is bad form, everything after the EndContext character ")" is not currently used in commands. So the commend character isn't necessary
			const std::string EndContext = ")";
			//everything before the StartContext character is read as the action. This includes spaces, and is case sensitive
			const std::string StartContext = "(";
			std::string action;
			std::string context;
			int actionstart, actionend = -1 * StartContext.size();
			actionstart = actionend + commentMarker.size();
			actionend = line.find(StartContext, actionstart);
			action = (line.substr(actionstart, actionend - actionstart));
			std::string remainder = command;
			remainder.erase(0, actionend + 1);

			//now isolate the context
			int contextstart, contextend = -1 * EndContext.size();
			contextstart = contextend + commentMarker.size();
			contextend = remainder.find(EndContext, contextstart);
			context = (remainder.substr(contextstart, contextend - contextstart));

			//Storage for strings "n(ew) string cont(ext)"
			std::string nstringcont = "";

			if (context.size() >= 3) {
				if ((context.find('"')) != std::string::npos) {
					nstringcont = context.substr(1, context.size() - 2);
				}
				else {
					nstringcont = context;
				}
			}

			//if trees
			if (action == "log") { //TODO: implement backmoving in file tree
				if (currentLog.is_open()) {
					time_t timestamp;
					char str[26];
					time(&timestamp);
					ctime_s(str, sizeof str, &timestamp);
					currentLog << "\nClosing log at " << str << std::endl;
					currentLog.close();
				}
				if (openfile.is_open()) {
					time_t timestamp;
					char str[26];
					time(&timestamp);
					ctime_s(str, sizeof str, &timestamp);
					openfile << "\nClosing log at " << str << std::endl;
					openfile.close();
				}
				currentLog.open(ABSPATH + nstringcont);

				if (currentLog.is_open()) {
					time_t timestamp;
					char str[26];
					time(&timestamp);
					ctime_s(str, sizeof str, &timestamp);
					currentLog << "Created new log at " << str << std::endl;
				}
				else {
					char errmsg[94];
					strerror_s(errmsg, sizeof(errmsg), errno);

					std::cout << "ERROR! CANNOT OPEN LOG FILE!" << "\n" << errmsg << "\n\n" << (ABSPATH + nstringcont) << "\n" << std::endl;
				}
			}
			else if (action == "print") {
				if (openfile.is_open()) {
					openfile << ScriptName << ": " << nstringcont << std::endl;
				}
				else {
					currentLog << ScriptName << ": " << nstringcont << std::endl;
				}
				std::cout << "printing!" << std::endl;
			}
			else if (action == "open") {
				readScriptFile(ABSPATH + nstringcont, currentLog);
				std::cout << "opening!" << std::endl;
			}
			else if (action == "closelog") {
				time_t timestamp;
				char str[26];
				time(&timestamp);
				ctime_s(str, sizeof str, &timestamp);
				if (openfile.is_open()) {
					openfile << "\nClosing log at " << str << std::endl;
					openfile.close();
				}
				else {
					currentLog << "\nClosing log at " << str << std::endl;
					currentLog.close();
				}
				
			}
			else {
				std::cout << "invalid command!" << std::endl;
			}
		}

		f.close();
	}
}