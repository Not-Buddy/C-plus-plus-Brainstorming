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
  int flag,t;
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
	  int nums{};
	  cin>>nums;

	flag=0;

	for(int j{0};j<nums;j++)
	{
		cin>>t;
		if(t<=j*2||t<=(nums-j-1)*2)flag=1;
	}
	if(flag)cout<<"NO\n";
	else cout<<"YES\n";
  }
  return 0;
}
