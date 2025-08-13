#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main()
{
  int testcases{};
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
	int n{},k{};
	cin>>n>>k;

	std::vector<int> S(n),T{};
	map<int, int> mpt{};

	for(int j{0};j<n;j++) cin>>S[j];


	for(int j{0};j<n;j++)
	{
		int x;
		cin>>x;
		x%=k;
		mpt[x]++;
	}

	for(int j{0};j<n;j++)
	{
		int x=S[j]%k;
		if(mpt[x])
		{
			mpt[x]--;
			continue;
		}
		if(mpt[k-x])
			mpt[k-x]--;
	}

	int cnt{0};
	for(auto e:mpt)
	{
		if(e.ss!=0)cnt++;
	}
	if(cnt) cout<<"NO";
	else cout<<"YES";

  }

  return 0;
}
