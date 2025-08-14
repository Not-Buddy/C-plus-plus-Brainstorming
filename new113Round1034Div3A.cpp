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
	int n{};
	cin>>n;
	std::vector <int> Line1(n),Line2(n);
	for(int j{0};j<n;j++)
		cin>>Line1[j];
	for(int j{0};j<n;j++)
		cin>>Line2[j];
	long long dec{},inc{};
	for(int j{0};j<n;j++)
	{
		if(Line1[j]>Line2[j]) dec+=Line1[j]-Line2[j];
	}
	cout<<dec+1<<"\n";

  }

  return 0;
}
