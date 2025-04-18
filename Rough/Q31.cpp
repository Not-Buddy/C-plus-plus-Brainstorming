#include <bits/stdc++.h> 
using namespace std;

int Squaring1toN(int a)
{
	int sum{};
	for(int i{1};i<=a;i++)
	{
		sum+=pow(i,2);
	}
	return sum;
}

int main()
{	

	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};
	cin>>input;

	cout<<"From 1 to N Square sum: "<<Squaring1toN(input)<<"\n";

	return 0;
}

