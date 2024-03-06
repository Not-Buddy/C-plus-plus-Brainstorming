#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool findInteger(const std::vector<int> &vec, int target) 
{
    for (int num : vec) 
    {
        if (num == target) 
        {
            return true;
        }
    }
    return false;
}


bool Checker(std::vector<int> &vec1,std::vector<int> &vec2,int k)
{
  int count1{0},count2{0}; //1 till k needed and each array can have k/2 elements
  int arr[k];
  for(int j{0};j<k;j++)
  {
    arr[j]=j+1;
  }
  for(int i{0};i<k;i++)
  {
    bool first,second;
    first=findInteger(vec1,arr[i]);
    second=findInteger(vec2,arr[i]);
    if(!first&&!second)
    {
      return false;
    }
    if(first)
    {count1++;}
    else if(second)
    {count2++;}
  }
  if(count1>k/2||count2>k/2){return false;}
  else{return true;}
}
void VectorMaker(std::string cases,vector <int> &vec1)
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
      vec1.push_back(std::stoi(dummy));
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
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    std::vector <int> vec1{};
    std::vector <int> vec2{};
    std::string case1{};
    std::string case2{};
    int n{},m{},k{};
    cin>>n>>m>>k;
    cin.ignore();
    getline(cin,case1);
    VectorMaker(case1,vec1);

    getline(cin,case2);
    VectorMaker(case2,vec2);
    
    bool answer=Checker(vec1,vec2,k);
    if(answer)
    {
      cout<<"YES"<<"\n";
    }
    else 
    {
      cout<<"NO"<<"\n";
    }

  }
  return 0;
}
