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
    ll n{},k{},x{},sum{};
    cin>>n>>k>>x;
    cin.ignore();
    ll max_val{},min_val{};
    min_val=(k*(k+1))/2;
    max_val=(n*(n+1))/2;
    ll max_sum=max_val-((n-k)*(n-k+1))/2;
    if(x>=min_val && x<=max_sum)
      cout<<"YES"<<endl;
    else 
      cout<<"NO"<<endl;
  }

  return 0;
}
