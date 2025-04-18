#include <bits/stdc++.h> 
using namespace std;

int main()
{	
	int sum{};
	for(int i{1};i<101;i++)
	{
		if(!(i&1))
			sum+=i;
	}
	cout<<"Sum: "<<sum<<"\n";
	return 0;
}

