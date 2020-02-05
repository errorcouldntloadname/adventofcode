#include <list>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void differbyone(string ID1, string ID2);
bool containsMultiple(string ID,int multiple);	//returns true if any character is exactly "multiple" times 
int checksum(list<string> datalist);


//--------------------->  MAIN   <----------------------
int main()
{
	//Variables
	ifstream data("warehouse.dat");		//input data object
	list<string> datalist;
	string current;
	list<string>::iterator it;
	list<string>::iterator it2;

	
	//read input into single list	
	for(int i = 0; i < 250; i++) {
		data>>current;
		datalist.push_back(current);
	}

	for(it = datalist.begin(); it != datalist.end(); it++)	{
		for(it2 = it; it2 != datalist.end(); it2++){
			differbyone(*it,*it2)	
		}
	}
	//cout<<checksum(datalist)<<endl;
	return 0;
}
//------------------- End of main ------------------------


bool containsMultiple(string ID, int multiple)
{
	int count[26] = {0};
	for(int i = 0; i < ID.size(); i++)	{
		count[int(ID[i])-97]++;
	}
	for(int i = 0; i < 26; i++)	{
		if(count[i] == multiple)	return true;
	}
	return false;
}	//end of containsMultiple


int checksum(list<string> datalist)
{
	int count2 = 0;
	int count3 = 0;
	list<string>::iterator it;
	for(it = datalist.begin(); it != datalist.end(); it++)	{
		if(containsMultiple(*it,2))		count2++;
		if(containsMultiple(*it,3))		count3++;
	}
	cout<<count2<<endl<<count3<<endl;
	return count2*count3;
}	//end of checksum



//checks if the 2 IDs differ by exactly one letter
void differbyone(string ID1, string ID2)
{
	string sameChars = "";
	
	for(int i = 0; i < ID1.size();i++)	{
		if(ID1[i] != ID2[i])		sameChars += ID[i];
	}
	if(sameChras.size() == ID1.size() -1)	cout<<sameChars<<endl;
}
