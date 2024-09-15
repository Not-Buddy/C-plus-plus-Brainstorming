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

int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	  int x{},y{},k{};
	  std::pair <int,int> pos{0,0};
	  std::cin>>x>>y>>k;
	  cin.ignore();
		int j{0},steps{0};
	  while(pos.first!=x&&pos.second!=y)
	  {
		if(j%2==0)
		{
			if(x-pos.first>k)
			{
				pos.first+=k;
			}
			else 
			{
				pos.first+=x-pos.first;
			}
			steps++;
		}
		else
		{
			if(y-pos.second>k)
			{
				pos.second+=k;
			}
			else
			{
				pos.second+=y-pos.second;
			}

			steps++;
		}

	  }
	  cout<<steps<<endl;

  }

  return 0;
}
