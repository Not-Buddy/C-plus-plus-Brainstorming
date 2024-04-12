#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef long long ll;
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

ll max(ll a,ll b)
{
  if(a>=b)
    return a;
  else 
    return b;
}

ll min(ll a,ll b) 
{
  if(a<=b)
    return a;
  else 
    return b;
}

  
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    ll a{},b{},m{};
    cin>>a>>b>>m;
   // cout<<"m/a:"<<m/a<<" m/b:"<<m/b<<endl;
    cout<<(m/a)+(m/b)+2<<endl; 
     
  }

  return 0;
}
