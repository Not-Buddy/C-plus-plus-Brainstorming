#include <bits/stdc++.h> 
using namespace std;



int main()
{	

	int input{},upper{};
	std::string Input{};
	cin>>input;
	for(int i{1};i<input;i++)
	{
		upper+=i;
	}

	cout<<"Sum of numbers from 1 till n: "<<upper<<"\n";


	return 0;
}

