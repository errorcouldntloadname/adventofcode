#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <tuple>
#include <map>
//reads file into list<string> breaks on first empty line
#include "readdata.h"
#include "readdata.cpp"

using namespace std;

list<tuple<int,int>> findcoords(string rectangle);

int main()
{
	list<string> data = readdata("fabric.dat");
	list<string>::iterator it;
	tuple<int,int> coordinate;
	map<tuple<int,int>,int> field;
	list<tuple<int,int>> coordlist;
	int iterator;
	coordlist = findcoords("#1 @ 896,863: 29x19");
	for(it = data.begin();it != data.end();it++)	{
		iterator++;		}
//		coordlist = findcoords(*it);
	return 0;
}

list<tuple<int,int>> findcoords(string rectangle)
{
	list<tuple<int,int>> output;
	int xpos = 0;
	int ypos = 0;
	int xlen = 0;
	int ylen = 0;
	int pos0 = 0;
	int pos1 = 0;
	pos0 = rectangle.find("@");
	pos1 = rectangle.find(",");
	xpos=stoi(rectangle.substr(pos0,pos1-1));
	pos0 = rectangle.find(":");
	ypos=stoi(rectangle.substr(pos1,pos0-1));
	pos1 = rectangle.find("x");
	xlen = stoi(rectangle.substr(pos0,pos1-1));
	pos0 = rectangle.size();
	ylen = stoi(rectangle.substr(pos1,pos0-1));
	cout<<xpos<<endl<<ypos<<endl<<xlen<<endl<<ylen<<endl;
	return output;
}
