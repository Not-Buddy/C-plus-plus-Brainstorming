
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
//typedef long long ll;
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
void VectorDisplay(std::vector <int> const vec1)
{
  cout<<"{ ";
  for(int i:vec1)
  {
    cout<<i<<" ";
  }
  cout<<"}"<<endl;
}

void solve(int a, int b, int &output)
{
	vector <int> outputs{};
	for(int i{a};i<=b;i++)
	{
		outputs.push_back((i-a)+(b-i));
	}
	output=*std::max_element(outputs.begin(),outputs.end());
}
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	  std::vector <int>values{};
	  std::string input;
	  std::getline(std::cin,input);
	  vectormaker(values,input);
	  int output{0};
	  if(values[0]==values[1])
	  {
		  output=0;
	  }
	  else if(values[0]<values[1])
	  {
		  solve(values[0],values[1],output);
	  }

	  cout<<output<<endl;

  }

  return 0;
}
