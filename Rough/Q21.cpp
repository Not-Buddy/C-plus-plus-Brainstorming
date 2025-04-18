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
	std::string Input{};
	std::string vowels="aeiou";
	cin>>Input;

	for(auto ch:Input)
	{
		for(auto v:vowels)
		{
			if(v==ch)
				input++;
		}
	}

	cout<<"Number of vowels in "<<Input<<" is "<<input;


	return 0;
}

