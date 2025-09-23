#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	  std::string input{};
	  getline(cin,input);
		sort(input.begin(), input.end());
		reverse(input.begin(), input.end());
		cout<<input<<"\n";
  }
	return 0;
}
