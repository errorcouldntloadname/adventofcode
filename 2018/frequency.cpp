#include <list>
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> lookup;
	unordered_set<int> *lookpoint = &lookup;
	list<int> datalist;
	list<int>::iterator it;
	int frequency = 0;	//stores the current frequency
	int current = 0;	//current frequency read from data	
	ifstream data;		//input data object
	data.open("frequency.dat");
	//read input into single list	
	for(int i = 0; i < 994; i++) {
		data>>current;
		datalist.push_back(current);
	}

	//update frequency
	for(it = datalist.begin();it != datalist.end();it++)  {
		frequency = frequency + *it;
	}
	
	cout<<frequency<<endl;
	return 0;
}
