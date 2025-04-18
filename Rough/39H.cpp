#include <bits/stdc++.h> 
using namespace std;

int main()
{	

	int input{},upper{};
	
	std::vector<int> sample{0,1};
	cin>>input;
	int it{1};
	for(int i{0};i<input;i++)
	{
		for(int j{0};j<i;j++)
		{
			cout<<it<<" ";
			it++;
		}
		cout<<"\n";
	}

	return 0;
}

