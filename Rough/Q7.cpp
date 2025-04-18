#include <bits/stdc++.h> 
using namespace std;

int main()
{	

	//5 5*4*3*2*1
	int n{7},facto{};

	for(int i{1};i<=50;i++)
	{
		if(i%7==0)
		{
			facto++;
		}
	}
	cout<<"Divisible by 7 in 1-50 are :"<<facto<<"\n";

	return 0;
}

