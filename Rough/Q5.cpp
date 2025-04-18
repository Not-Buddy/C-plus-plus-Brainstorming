#include <bits/stdc++.h> 
using namespace std;

int main()
{	

	//5 5*4*3*2*1
	int n{},facto{1};
	cin>>n;

	for(int i{1};i<=n;i++)
	{
		facto*=i;
	}

	cout<<"Factorial: "<<facto<<"\n";
	return 0;
}

