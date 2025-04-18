#include <bits/stdc++.h> 
using namespace std;

void ReversingString(std::string &loma)
{
	int n=loma.size()-1;
	std::string rev{};
	for(int i{n};i>=0;i--)
	{
		rev+=loma[i];
	}
	loma=rev;
}

int main()
{	

	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};
	getline(cin,Input);

	ReversingString(Input);
	cout<<"Reversed String: "<<Input<<"\n";

	return 0;
}

