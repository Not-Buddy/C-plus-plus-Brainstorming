#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main()
{
  int testcases{};
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
	  int n{}; cin>>n;
	  vector<pair<pair<int,int>,int>> v(n);
	  for(auto &[x,y]:v){cin>>x.first>>x.second;x.second=-x.second;}
	  for(int i{0};i<n;i++)v[i].second=i;
	  sort(v.begin(),v.end());

	  int mn=-1e9;
	  vector<int>ans;
	  for(int i{0};i<n;i++)
	  {
		  if(v[i].first.first>mn)
		  {
			  mn=v[i].first.first;
			  ans.push_back(v[i].second+1);
		  }
	  }
	  cout<<ans.size()<<"\n";
	  for(auto &x:ans)cout<<x<<" ";
	cout<<"\n";
  }

  return 0;
}
