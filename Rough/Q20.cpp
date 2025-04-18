#include <bits/stdc++.h> 
using namespace std;



int GetDigits(int a)
{
	int digits{0};
	while(a!=0)
	{
		a/=10;
		digits++;
	}
	return digits;
}

bool isArmstrong(int a, int digits)
{
	int Arm{};
	int copy=a;
	while(a!=0)
	{
		int digit=a%10;
		a/=10;
		int add=pow(digit,digits);
		Arm+=add;
	}
	if(Arm==copy)
		return true;
	return false;

}
int main()
{	

	int input{},upper{};

	
	std::vector<int> sample{0,1};
	
	for(int i{1};i<=999;i++)
	{
		//double result = pow(base,exponent);
		//
		int digits=GetDigits(i);
		if(isArmstrong(i,digits))
		{
			cout<<i<<" ";
		}

	}

	return 0;
}

