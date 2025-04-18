#include <bits/stdc++.h> 
using namespace std;

bool isPrime(int n)
{
	int factors{};
	for(int i{0};i<=n;i++)
	{
		if(n%i==0)
			factors++;
	}
	if(factors==2)
		return true;
	return false;
}

int main()
{	

	int input{},input2{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};
	std::vector<std::pair<int ,int>> TwinPrimes{};

	for(int i{1};i<=98;i++)
	{
		if(isPrime(i)&&isPrime(i+2))
			TwinPrimes.push_back({i,i+2});
	}
	
	for(auto lol:TwinPrimes)
	{
		cout<<lol.first<<" "<<lol.second<<"\n";
	}


	return 0;
}

