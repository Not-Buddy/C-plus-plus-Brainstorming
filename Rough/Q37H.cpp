#include <bits/stdc++.h> 
using namespace std;


int GetLCM(int a, int b)
{
	int bigger=max(a,b);
	int smaller=min(a,b);

	while(bigger!=0)
	{
		int temp=smaller;
		smaller=bigger%smaller;
		bigger=temp;
	}
	return (a*b)/smaller;
}
int main()
{	

	int input{},input2{},reverse{};
	std::string Input{};

	cin>>input;
	cin>>input2;

	int LCM=GetLCM(input,input2);
	cout<<LCM<<"\n";

	

	return 0;
}

