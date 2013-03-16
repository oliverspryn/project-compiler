#include <iostream>

#include "OptionParser.h"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
	OptionParser parser(argc, argv);
	string stuff = parser.getArgument(2);
	cout << stuff << endl;

	return 0;
}