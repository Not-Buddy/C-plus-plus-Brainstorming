#include <bits/stdc++.h> 
using namespace std;


int main()
{	

	int input{},upper{};

	cin>>input;
	
	std::vector<int> sample{0,1};
	
	for(int i{1};i<=input;i++)
	{
		int temp=sample[0]+sample[1];
		sample[0]=sample[1];
		sample[1]=temp;
		cout<<"Ith term: "<<i<<" is "<<sample[0]<<"\n";
	}

	return 0;
}

