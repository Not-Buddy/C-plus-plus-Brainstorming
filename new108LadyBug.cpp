#include <iostream>
#include <string>
#include <cctype>
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

	  std::string Bin1{};
	  std::string Bin2{};
	  getline(cin,Bin1);
	  getline(cin,Bin2);
	if(Bin1==Bin2) cout<<"YES"<<"\n";

	else
	{
	  //012345
	  //010001 (a)
	  //010111 (b)
	  // swap (a4,b3)
	  //
	  //notpossible case
	  //10000
	  //01010
	int countzeroA{},countzeroB{};
	for(int j{0};j<n;j++)
	{
		if(Bin1[j]=='0')
			countzeroA++;
		else if(Bin2[j]=='0')
			countzeroB++;
	}
	int count1A=n-countzeroA;
	int count1B=n-countzeroB;
	int countTotalzero=countzeroA+countzeroB;
	cout<<(countTotalzero%2==0?"YES":"NO")<<"\n";
	}

  }

  return 0;
}
