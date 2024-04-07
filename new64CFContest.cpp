#include <iostream>
#include <cmath>
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

ll vectorsum(std::vector <ll> &vec)
{
  ll sum;
  for(ll i{0};i<vec.size();i++)
  {
    sum+=vec[i];
  }
  return sum;
}

int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    std::vector <ll> arr{};
    std::string input{};
    getline(cin,input);
    vectormaker(arr,input);
    ll tentsneeded{},remainder1{};
    int flag{0};
    tentsneeded=arr[0];
    remainder1=3-arr[1]%3;
    arr[1]+=remainder1;
    arr[2]-=remainder1;
    cout<<"remainder1: "<<remainder1<<" "<<arr[1]<<" "<<arr[2]<<endl;
  }

  return 0;
}