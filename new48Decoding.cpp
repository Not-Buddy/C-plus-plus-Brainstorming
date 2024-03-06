#include <iostream>
#include <vector>
#include <string>
using namespace std;
  std::string string1{};
int main()
{
  int length{};
  cin>>length;

  std::string val{};
  cin.ignore();
  getline(cin,val);
  if(length%2!=0)
  {
  for(int i{0};i<length;i++)
  {
    if(i%2==0)
    {
      string1.push_back(val[i]);
    }
    else 
    {
      string1.insert(string1.begin(),val[i]);
    }
  }
  }
  else 
  {
  for(int i{0};i<length;i++)
  {
    if(i%2!=0)
    {
      string1.push_back(val[i]);
    }
    else 
    {
      string1.insert(string1.begin(),val[i]);
    }
  }

  }
  cout<<string1<<"\n";
  return 0;
}
