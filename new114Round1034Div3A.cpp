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
	if(n%4!=0)
		cout<<"Alice"<<"\n";
	else 
		cout<<"Bob"<<"\n";


  }

  return 0;
}
