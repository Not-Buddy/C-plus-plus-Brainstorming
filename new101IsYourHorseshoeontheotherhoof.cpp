#include <iostream>
#include <set>
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
    std::vector <int> Input{};
    int max{};
    std::set<int> mySet;
    std::string InputLine{};
    getline(cin,InputLine);
    vectormaker(Input,InputLine);
    for(int i{0};i<4;i++)
    {
      mySet.insert(Input[i]);
    }
   cout<<4-mySet.size()<<endl; 
    





  return 0;
}
