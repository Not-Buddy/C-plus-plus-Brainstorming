#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

void vectormaker(std::vector <int>&vec1,std::string input)
{
  std::string digit{};
  for(int i{0};i<input.size();i++)
  {
    while(std::isdigit(input[i]))
    {
      digit.push_back(input[i]);
      i++;
    }
    vec1.push_back(std::stoi(digit));

    digit.clear();
  }
}
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	int n{};
	cin>>n;
	cin.ignore();

	std::vector<int> Input{};
	std::string Input_str{};
	getline(cin,Input_str);
	vectormaker(Input,Input_str);
	
	unordered_map<int,int> hash{};
	for(auto lol:Input)
	{
		hash[lol]++;
	}
	
	int one{},morethanone{};
	for(auto lol2:hash)
	{
		if(lol2.second==1)
			one++;
		else if(lol2.second>1)
			morethanone++;
	}

	cout<<morethanone+(one+1)/2*2<<'\n';


  }

  return 0;
}
