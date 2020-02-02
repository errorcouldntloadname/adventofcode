#include <list>
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

bool checkDuplicate(unordered_set<int> *lookpoint,int frequency);

int main()
{
	unordered_set<int> lookup;
	unordered_set<int> *lookpoint = &lookup;
	list<int> datalist;
	int frequency = 0;	//stores the current frequency
	int current = 0;	//current frequency read from data	
	ifstream data;		//input data object
	data.open("frequency.dat");
	//read input into single list	
	for(int i = 0; i < 994; i++) {
		data>>current;
		datalist.push_back(current);
	}

	list<int>::iterator it = datalist.begin();
	//update frequency
	while (true)  {
		frequency = frequency + *it;
		//check if its a duplicate,otherwise add to set of unique frequencies
		if (checkDuplicate(lookpoint,frequency))	break;
		it++;
		if (it == datalist.end())	it = datalist.begin();
	}
	

	cout<<frequency<<endl;
	return 0;
}

bool checkDuplicate(unordered_set<int> *lookpoint,int frequency)
{
	if (lookpoint->count(frequency) != 0)  return true;
	else	{
		lookpoint->insert(frequency);
		return false;
	}
}

