#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

vector<int> solve(int n)
{
	if(n==1) return {0};
	vector<int> ans;
	for(int i{0};i<n/2;i++)
	{
		ans.push_back(-1);
		ans.push_back(3);
	}
	if(n%2==1)
		ans.push_back(-1);
	else 
		ans.back()=2;
	return ans;
}

int main()
{
  int testcases{};
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
	int n{};
	cin>>n;
	std::vector<int> ans=solve(n);

	for(int i{0};i<n;i++)
		cout<<ans[i]<<(i+1<n?' ':'\n');

  }

  return 0;
}
