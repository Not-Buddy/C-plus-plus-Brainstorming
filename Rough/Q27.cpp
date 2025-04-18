#include <bits/stdc++.h> 
using namespace std;


int fibo(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fibo(n-1)+fibo(n-2);
}
int main()
{	

	int input{},reverse{};
	std::string Input{};
	cin>>input;

	int fibon=fibo(input);

	cout<<"Nth fibo number: "<<fibon<<"\n";

	return 0;
}

