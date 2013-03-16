#include "OptionParser.h"

OptionParser::OptionParser(int argc, char **argv) : argIndex(argc), argValues(argv) {
	
}

bool OptionParser::isOption(int index) {
	return this->argValues[index][0] == '-';
}

vString OptionParser::getOption(int index) {
	vString ret(2);
	string option = this->argValues[index];

//Strip off the "-" before the option
	if (option.at(1) == '-') {
		option = option.substr(2, option.length() - 1);
	} else {
		option = option.substr(1, option.length() - 1);
	}

//Split the string at the "=" to get the option and option value (if any)
	unsigned int found = option.find("=");

	if (found != string::npos) {
		ret[0] = option.substr(0, found);
		ret[1] = option.substr(found + 1, option.length() - 1);
	} else {
		ret[0] = option.substr(0, option.length());
		ret[1] = "";
	}

	return ret;
}

bool OptionParser::isArgument(int index) {
	return index != 0 && !this->isOption(index); //index == 0 is the command, and has the same structure as an argument
}

string OptionParser::getArgument(int index) {
	//this->isArgument(index) ? true : throw NotAnArgumentException(); 

	string ret = this->argValues[index];
	return ret;
}