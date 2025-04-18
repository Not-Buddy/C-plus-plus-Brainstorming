#include <bits/stdc++.h> 
using namespace std;

int main()
{	

	//5 5*4*3*2*1
	int n{},facto{1};

	std::vector<int> fibo{0,1};
	for(int i{0};i<10;i++)
	{
		cout<<fibo[0]<<" ,";
		int temp=fibo[0]+fibo[1];
		fibo[0]=fibo[1];
		fibo[1]=temp;
	}

	return 0;
}

