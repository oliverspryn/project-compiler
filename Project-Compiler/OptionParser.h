#ifndef __OPTIONPARSER_H
#define __OPTIONPARSER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

typedef vector<string> vString;
typedef vector<vector<string>> vvString;

class OptionParser {
public : 
	OptionParser(int argc, char **argv);
	vString getOption(int index);
	string getArgument(int index);

private : 
	bool isOption(int index);
	bool isArgument(int index);

	int argIndex;
	char **argValues;
};

#endif