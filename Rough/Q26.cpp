#include <bits/stdc++.h> 
using namespace std;
bool isPalindrome(int a)
{

	int reverse{};
	int copy=a;

	while(a!=0)
	{
		int digit=a%10;
		a/=10;
		reverse=reverse*10+digit;
	}
	if(reverse==copy)
		return true;
	return false;
}

int main()
{	

	int input{},reverse{};
	std::string Input{};
	cin>>input;


	//Right angled triagnle
	//
	if(isPalindrome(input))
	{
		cout<<"Yes"<<"\n";
	}
	else
	{
		cout<<"No"<<"\n";
	}

	return 0;
}

