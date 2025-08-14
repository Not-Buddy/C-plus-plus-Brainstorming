#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <climits>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main()
{
  int testcases{};
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
	int n{},j{},k{};
	cin>>n>>j>>k;
	std::vector<int> powers(n);
	for(int i{0};i<n;i++) cin>>powers[i];

	std::vector<int> lastk{};
	for(int i{0};i<n;i++)
	{
		if(powers[i]>=j)
			lastk.push_back(powers[i]);
	}
	sort(lastk.begin(),lastk.end());
	int size = lastk.size();
	if(j>=lastk[size-1]&&k<=size)
		cout<<"YES"<<"\n";
	else 
		cout<<"NO"<<"\n";


  }

  return 0;
}
