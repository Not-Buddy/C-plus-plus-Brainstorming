#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

char max_occured(std::string InputString)
{

  if(InputString.empty()) return '\0';

  std::unordered_map<char,int> hash{};
  for(char c:InputString)
  {
    hash[c]++;
  }

	char biggestele{InputString[0]};
	int max=hash[biggestele];
	for(auto ele:hash)
	{
		if(ele.second>max)
		{
			biggestele=ele.first;
			max=ele.second;
		}
	}
    return biggestele; 
}

char min_occured(const std::string InputString)
{
	if(InputString.empty()) return '\0';

	std::unordered_map<char,int> hash{};
	for(char c:InputString)
	{
		hash[c]++;
	}
	char smallestele{InputString[0]};
	int min=hash[smallestele];
	for(auto ele:hash)
	{
		if(ele.second<min)
		{
			smallestele=ele.first;
			min=ele.second;
		}
	}
    return smallestele;
}

int main()
{
  int testcases{};
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
      int n{};
      cin>>n;
      std::string InputString{};
      cin>>InputString;

      //Edge case 1
      if(InputString.size()==1)
      {
        cout<<InputString<<'\n';
      }
      else 
      {
       //Find most occured element and replace that
        std::vector <std::pair<char,int>> pairs{};
        int len=InputString.size();
        char max=max_occured(InputString);
	char min=min_occured(InputString);

	//cout<<"Max Element: "<<max<<" Case:"<<i<<'\n'<<"Min Element: "<<min<<'\n';
	if(max!=min)
	{
        for(int i{0};i<len;i++)
        {
          if(min==InputString[i])
          {
            InputString[i]=max;
            break;
          }
        }
	}
	else 
	{
        for(int i{0};i<len;i++)
        {
          if(max!=InputString[i])
          {
            InputString[i]=max;
            break;
          }
        }
	}
        cout<<InputString<<'\n';
      } 
  }

  return 0;
}
