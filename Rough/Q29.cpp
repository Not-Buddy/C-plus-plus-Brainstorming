#include <bits/stdc++.h> 
using namespace std;

void MakeEven(std::vector<int> &loma)
{
	std::vector<int> evens{};
	int n=loma.size();
	for(int i{0};i<n;i++)
	{
		if(loma[i]%2==0)
			evens.push_back(loma[i]);
	}
	loma=evens;
}

int main()
{	

	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};

	MakeEven(loma);
	
	
	for(auto l:loma)
	
	{
		cout<<l<<" ";
	}


	




	return 0;
}

