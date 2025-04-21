#include <bits/stdc++.h> 
using namespace std;

int main()
{	
	//Sieve of Eratosthenes

	int n{},upper{};
	

	cin>>n;
	std::vector<bool> isPrime(n+1,true);
	isPrime[0]=isPrime[1]=false;
	for(int i{2};i<=n;i++)
	{
		if(isPrime[i]&&(long long)i*i<=n)
		{
			for(int j{i*i};j<=n;j+=i)
				isPrime[j]=false;
		}
	}

	for(int i{0};i<n;i++)
	{
		if(isPrime[i])
			cout<<i<<" ";
	}


	return 0;
}

