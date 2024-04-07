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

void vectormaker(std::vector <int>&vec1,std::string input)
{
  std::string digit{};
  for(ll i{0};i<input.size();i++)
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
void VectorDisplay(std::vector <ll> const vec1)
{
  cout<<"{ ";
  for(ll i:vec1)
  {
    cout<<i<<" ";
  }
  cout<<"}"<<endl;
}

ll min(double const a,int const b)
{
  if(a>=b)
    return b;
  else 
    return a;
}

int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    std::string input{};
    std::vector <int> vec{};
    ll n{},f{},a{},b{};
    cin>>n>>f>>a>>b;
    cin.ignore();
    getline(cin,input);
    vectormaker(vec,input);
    vec.insert(vec.begin(),0);

    for(int ii{1};ii<n+1;ii++)
    {
      ll diff=a*(vec[ii]-vec[ii-1]);
      f-=min(diff,b);
    //  cout<<"f:"<<f<<" chargetot:"<<diff<<" b:"<<b<<endl;
    }
    f>0?cout<<"YES"<<endl:cout<<"NO"<<endl;

    //for(auto sub:vec)
    //{
     // cout<<sub<<",";
    //}
    //cout<<endl;

  }

  return 0;
}
