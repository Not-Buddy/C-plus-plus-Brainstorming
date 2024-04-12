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
void VectorDisplay(std::vector <int> const vec1)
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
    vector <int> vec{};
    int a{},b{},c{},a_out{0},b_out{0},c_out{0};
    cin>>a>>b>>c;
    cin.ignore();
    for(int i{0};i<a;i++)
    {
      vec.push_back(1);
    }
    for(int i=vec.size();i<+a+b;i++)
    {
      vec.push_back(2);
    }
    for(int i=vec.size();i<a+b+c;i++)
    {
      vec.push_back(3);
    }
    std::vector <int> vec1=vec,vec2=vec,vec3=vec;
    //VectorDisplay(vec);
    while(std::find(vec1.begin(),vec1.end(),2)!=vec1.end())
    { 
    }
  

  }

  return 0;
}
