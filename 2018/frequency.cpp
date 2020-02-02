#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int frequency = 0;	//stores the current frequency
	int current = 0;	//current frequency read from data	
	ifstream data;		//input data object
	data.open("frequency.dat");

	for(int i = 0; i < 994; i++) {
		data>>current;
		frequency = frequency + current;
		cout<<frequency<<endl;	
	}
	return 0;
}
