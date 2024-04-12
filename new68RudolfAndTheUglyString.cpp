 
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;
 
ll factorial_sum(ll input)
{
  ll sum{0};
  for(ll i{1};i<=input;i++)
  {
    sum+=i;
  }
  return sum;
}
 
int BinSearch(std::vector <int> const vec,int key)
{
  int l{},h{},mid{};
  h=vec.size()-1;
  while(l<=h)
  {
    mid=(l+h)/2;
    if(key==vec[mid])
      return mid;
    else if(key<vec[mid])
      h=mid-1;
    else 
      l=mid+1;
  }
  return -1;
}
 
void vectormaker(std::vector <ll>&vec1,std::string input)
{
  std::string digit{};
  for(ll i{0};i<input.size();i++)
  {
    while(std::isdigit(input[i]))
    {
      digit.push_back(input[i]);
      i++;
    }
    vec1.push_back(std::stoull(digit));
 
    digit.clear();
  }
}
void VectorDisplay(std::vector <ll> const vec1)
{
  cout<<"{ ";
  for(ll i:vec1)
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
    int n{},mapcount{},piecount{};
      cin>>n;
      cin.ignore();
    std::string input{};
    getline(cin,input);
    //cout<<"CASE: "<<i+1<<endl;
    if(input.size()>3)
    {
      for(int ii{0};ii<input.length()-2;ii++)
      {
        std::string compare=input.substr(ii,3);
        if(compare=="map")
        {
          mapcount++;
          input[ii+2]='?';
        }
        if(compare=="pie")
        {
         piecount++;
         input[ii]='?';
        }
        //cout<<"substr: "<<ii <<" : "<<compare<<endl;
      }
    }
    else 
    {
      if(input=="pie"||input=="map")
        mapcount++;
    }
    
      //cout<<"Case: "<<i<<" string: "<<input<<" mapcount: "<<mapcount<<" piecount: "<<piecount<<endl;
      cout<<mapcount+piecount<<endl;
 
 
  }
 
  return 0;
}
