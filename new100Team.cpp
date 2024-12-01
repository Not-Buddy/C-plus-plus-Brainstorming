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
  int testcases{},totans{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    vector <int> singleline{};
    std::string InputLine{};
    getline(cin,InputLine);
    vectormaker(singleline,InputLine);
    int count=0;
    for(int j{0};j<3;j++)
    {
      if(singleline[j]==1)
        count++;
    }
    if(count>=2)
     totans++;
}
cout<<totans<<endl;
  return 0;
}
