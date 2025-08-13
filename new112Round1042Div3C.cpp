#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main()
{
  int testcases{};
  cin>>testcases;
  for(int j{0};j<testcases;j++)
  {
	int n{},k{};
	cin>>n>>k;

	std::vector<int> S(n),T(n);
	unordered_map<int, int> freqA{},freqB{};

	for(int i{0};i<n;i++) cin>>S[i];
	for(int i{0};i<n;i++) cin>>T[i];

	for(int i{0};i<n;i++)
	{	
			freqA[S[i]%k]++;
			freqB[T[i]%k]++;
	}
	for(auto x:freqA)
	{
		if(freqB.find(x.first)!=freqB.end())
		{
			freqA[x.first]-=freqB[x.first]; //zero A out if found
			freqB[x.first]-=0;		//zero B out if found
			if(freqA[x.first]<0)
			{
				freqB[x.first]-=freqA[x.first];
				freqA[x.first]=0;
			}

		}
		if(freqB.find(k-x.first)!=freqB.end())
		{
			freqA[x.first]-=freqB[k-x.first];
			freqB[k-x.first]=0;
			if(freqA[x.first]<0)
			{
				freqB[k-x.first]-=freqA[x.first];
				freqA[x.first]=0;
			}
		}
	}
	string ans="YES";
	for(auto it:freqA)
	{
		if(it.second>0)
		{
			ans="NO";
			break;
		}
	}
	for(auto it:freqB)
	{
		if(it.second>0)
		{
			ans="NO";
			break;
		}
	}
	cout<<ans<<"\n";

  }

  return 0;
}
