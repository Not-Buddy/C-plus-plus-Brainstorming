#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void shiftL(int number_rotated, int &lock, int &zeros)
{
	if(lock == 0)
	{
		int crossings = number_rotated/100;
		zeros += crossings;
	}
	else if(number_rotated >= lock)
	{
		int crossings = 1 +(number_rotated - lock) /100;
		zeros+=crossings;
	}
	lock = (lock - number_rotated %100 + 100) % 100;
}

void shiftR(int number_rotated, int &lock, int &zeros)
{
	 int crossings = (lock + number_rotated)/100;
	 zeros += crossings;
	 lock = (lock + number_rotated) % 100;
}

int main()
{
	ifstream inputFile("input.txt");
	if(!inputFile.is_open())
	{
		cerr << "Error: Cannot open input.txt\n";
		return 1;
	}
	
	int lock = 50;
	int zeros = 0;
	string input;
	
	while(getline(inputFile, input))
	{
		input.erase(std::remove(input.begin(), input.end(), ' '),
			input.end());
			
		if(input.size()< 2)
			continue;

		int number_rotated = stoi(input.substr(1));

		if(input[0]=='L')
			shiftL(number_rotated, lock, zeros);
		else if(input[0] == 'R')
			shiftR(number_rotated, lock, zeros);
	}
	inputFile.close();
	cout<<zeros<<endl;
	
	return 0;
}
