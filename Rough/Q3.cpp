#include <bits/stdc++.h> 
using namespace std;

int main()
{	
	int n{};
	cin>>n;
	cout<<"Multiplication table"<<" of "<<n<<"\n";
	for(int i{1};i<=10;i++)
	{
		cout<<i <<":"<<i*n<<"\n";
	}
	

	return 0;
}

