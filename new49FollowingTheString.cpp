#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

void VectorMaker(std::string cases,std::vector <int> &vec,int strlen)
{
  std::string dummy{};
  for(int i{0};i<cases.size();i++)
  {
  if(std::isdigit(cases[i]))
  {
    while(std::isdigit(cases[i]))
    {
     dummy.push_back(cases[i]);
     i++;
    }
    vec.push_back(std::stoi(dummy));
    dummy.clear();
  }
  else 
  {
    i++;    
  }
  }
}
int main()
{
  int testcase{},strlen{};
  std::vector <int> vec{};
  std::string cases{};
  std::string outval{};
  cin>>testcase;
  cin.ignore();
  for(int i{0};i<testcase;i++)
  {
  std::unordered_map<char,int>myMap{{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},{'y',0},{'z',0}};
    cin>>strlen;
    cin.ignore();
    getline(cin,cases);
    VectorMaker(cases,vec,strlen);
    for(auto v1:vec)
    {
      for(auto it=myMap.begin();it!=myMap.end();it++)
      {
     //   cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
        if(v1==it->second)
        {
          //cout<<"v1: "<<v1<< " "<<it->first<<" "<<it->second<<endl;
          outval.push_back(it->first);
          it->second+=1;
          break;
        }
      }

    }
   cout<<outval<<endl; 
   outval.clear();
   vec.clear();
  }
  return 0;
}
