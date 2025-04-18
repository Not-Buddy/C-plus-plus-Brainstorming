#include <bits/stdc++.h> 
using namespace std;


int Reverse(int a)
{
	int digit{};
	int reverse;
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
	cin>>input;

	cout<<"Number entered: "<<input
		<<" Reversed: "<<Reverse(input);


	return 0;
}

