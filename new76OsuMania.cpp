
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
	  std::vector <std::string> input{};
	  std::vector <int> output_vec{};
	  int n{};
	  cin>>n;
	  cin.ignore();
	  for(int ii{0};ii<n;ii++)
	  {
	  	std::string buffer;
	  	std::getline(std::cin,buffer);
	  	input.push_back(buffer);
	  	buffer.clear();
	  }

	  for(int j=input.size()-1;j>=0;j--)
	  {
		  for(int k{0} ;k<input[j].size();k++)
		  {
			if(input[j][k]=='#')
			{
				k+=1;
				output_vec.push_back(k);
				break;
			}
		  }
	  }

	  for(auto out:output_vec)
	  {

		  cout<<out<<" ";
	  }
	  cout<<endl;

	


  }

  return 0;
}
