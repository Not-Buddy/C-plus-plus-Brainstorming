#include <bits/stdc++.h> 
using namespace std;

bool isPrime(int a)
{
	int factors{};
	for(int i{1};i<=a;i++)
	{
		if(a%i==0)
			factors++;
	}

	if(factors==2)
		return true;
	return false;

}

int main()
{	

	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};
	cin>>input;

	cout<<"Prime Check for "<<input<<" is "<<(isPrime(input)?"true":"false")<<"\n";

	return 0;
}

