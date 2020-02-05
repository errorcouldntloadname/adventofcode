#include "readdata.h"
#include <fstream>
#include <list>
#include <string>

using namespace std;

list<string> readdata(string filename)
{
	ifstream data;
	data.open(filename);
	char reading[256];
	string line;
	list<string> output;
	while(true) {	//breaks if input file is done
		data.getline(reading,256);
		line = reading;
		if(line == "")	break;
		output.push_back(line);
	}
	return output;
}
