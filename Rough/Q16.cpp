#include <bits/stdc++.h> 
using namespace std;


bool isPrime(int const a)
{
	int divisible{0};
	for(int i{1};i<=a;i++)
	{
		if(a%i==0)
			divisible++;
	}
	if(divisible>2)
	{
		return false;
	}
	return true;
}


void PrintPrime(const int a, const int b)
{
	for(int i{a};i<=b;i++)
	{
		if(isPrime(i))
		{
			cout<<i<<" ";
		}
	}
}
int main()
{	

	int lower{},upper{};
	cin>>lower;
	cin>>upper;

	cout<<"Prime from:"<<lower<<" till "<<upper<<"\n";
	PrintPrime(lower,upper);



	return 0;
}

