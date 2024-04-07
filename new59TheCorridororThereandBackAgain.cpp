#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <utility>
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
    ll trapnumber;
    
    cin>>trapnumber;
    cin.ignore();
    std::vector <std::pair<ll,ll>> storage{};
    std::vector <int> storage2{};
    for(ll ii{0};ii<trapnumber;ii++)
    {
      std::pair<ll,ll> input{};
      cin>>input.first>>input.second;
      cin.ignore();
      storage.push_back(input);
    }
    std::sort(storage.begin(),storage.end(),[](const auto& a,const auto& b)
        {
        return a.first<b.first;
        });
    for(auto pair:storage)
    {
      ll k_value{},remainder{};
      remainder=(pair.second-1)/2;

      k_value=pair.first+remainder;
      //cout<<"Pair:"<<pair.first<<" "<<pair.second<<" k_value:"<<k_value<<endl;
      storage2.push_back(k_value);      
    }
    //cout<<"------"<<endl;

    auto minElement =std::min_element(storage2.begin(),storage2.end());
      if(minElement!=storage2.end())
      {
        cout<<*minElement<<endl;
      }
      else 
      {
        cout<<"0"<<endl;  
      }

  }

  return 0;
}
