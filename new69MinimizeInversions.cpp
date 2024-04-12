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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    //std::string input{};
//    std::vector <int> vec1{};
  //  std::vector <int> vec2{};
    int n{};
    cin>>n;
    cin.ignore();
    //getline(cin,input);
    //vectormaker(vec1,input);
    //getline(cin,input);
    //vectormaker(vec2,input);
        pair<int,int> ab[n];
        for(int i = 0;i < n;++i)
        {
            cin >> ab[i].first;
        }
        for(int i = 0;i < n;++i)
        {
            cin >> ab[i].second;
        }
        sort(ab,ab+n);
        for(int i = 0;i < n;++i)
        {
            cout << ab[i].first << ' ';
        }
        cout << "\n";
        for(int i = 0;i < n;++i)
        {
            cout << ab[i].second << ' ';
        }
        cout << "\n";
  }

  return 0;
}
