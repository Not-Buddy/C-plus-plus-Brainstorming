#include <bits/stdc++.h> 
using namespace std;

int main()
{	

	//5 5*4*3*2*1
	int n{},facto{};
	int sum{};
	std::vector<int> input(5);
	for(int i{0};i<5;i++)
	{
		cin>>input[i];
		sum+=input[i];
	}
	cout<<"Average: "<<sum/5<<"\n";



	return 0;
}

