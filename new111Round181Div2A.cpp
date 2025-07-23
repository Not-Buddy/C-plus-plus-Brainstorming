#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <utility>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;


bool NotValid(const std::string input)
{
	int n = input.size();
	for(int i{0};i<n;i++)
	{
		std::string slice = input.substr(i,3);
		if(slice=="FFT"||slice=="NTT")
			return true;
	}
	return false;
}
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	  std::string input{};
	  getline(cin,input);
	  int n=input.size();
		while(NotValid(input))
		{
			for(int i{0};i<n;i++)
			{
				std::string slice=input.substr(i,3);
				if(slice == "FFT")
					swap(input[i+1],input[i+2]);
				else if(slice == "NTT")
					swap(input[i],input[i+2]);
			}
		}  
		cout<<input<<"\n";
  	}

  return 0;
}
