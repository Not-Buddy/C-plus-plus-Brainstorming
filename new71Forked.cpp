#include <iostream>
#include <set>
#include <cmath>
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

std::vector<int> range(int start, int end, int step = 1) {
    std::vector<int> result;
    for (int i = start; i < end; i += step) {
        result.push_back(i);
    }
    return result;
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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    int a{},b{};
    std::pair<int,int> king{};
    std::pair<int,int> queen{};
    cin>>a>>b;
    cin.ignore();
    cin>>king.first>>king.second;
    cin.ignore();
    cin>>queen.first>>queen.second;
    cin.ignore();
    std::vector <std::pair<int,int>> dirs={{a,b},{a,-b},{-a,b},{-a,-b}
                                 ,{b,a},{b,-a},{-b,a},{-b,-a}};
    std::set<std::pair<int,int>> st1, st2;
    for(auto d:dirs)
    {
      int x=king.first+d.first;
      int y=king.second+d.second;

      st1.insert(make_pair(x,y));

      x=queen.first+d.first;
      y=queen.second+d.second;

      st2.insert(make_pair(x,y));
    }
    int ans=0;
    for(auto pos:st1)
    {
      if(st2.find(pos)!=st2.end())
        ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
