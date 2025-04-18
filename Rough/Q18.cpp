#include <bits/stdc++.h> 
using namespace std;


int Reverse(int a)
{
	int digit{};
	int reverse{0};
	while(a!=0)
	{
		digit=a%10;
		a/=10;
		reverse=reverse*10+digit;
	}
	return reverse;
}

int main()
{	

	int input{},upper{};

	for(int i{100};i<=200;i++)
	{
		int Reversed=Reverse(i);
		if(Reversed==i)
		{
			cout<<i<<" ";
		}
	}


	return 0;
}

