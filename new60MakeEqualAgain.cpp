//Will work on this sometime later kinda messed up with a lot of complications i made 
//Lol
//
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

ll countelement(std::vector <ll> &arr,ll element)
{
  ll count{};
  for(ll i{0};i<arr.size();i++)
  {
    //cout<<"Index "<<i<<" Compared to "<<arr[i]<<" element: "<<element<<endl;
    if(element==arr[i])
    {
      count++;
    }
  }
  arr.erase(std::remove(arr.begin(),arr.end(),element),arr.end());
  return count;
}

ll countelement_simple(std::vector <ll> &arr,ll element)
{
  ll count{};
  for(ll i{0};i<arr.size();i++)
  {
    //cout<<"Index "<<i<<" Compared to "<<arr[i]<<" element: "<<element<<endl;
    if(element==arr[i])
    {
      count++;
    }
  }
  arr.erase(std::remove(arr.begin(),arr.end(),element),arr.end());
  return count;
}

int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{1};i<testcases+1;i++)
  {
    ll array_size{};
    std::vector <ll> arr{};
    std::vector <ll> element_count_storage{};
    
    std::string input{};
      cin>>array_size;
      cin.ignore();
      getline(cin,input);
      vectormaker(arr,input);
      
      ll l{0},h{array_size},start{0},digits1{0},digits2{},digits3{};
        for(ll ii{0};ii<array_size;ii++)
        {
          if(arr[ii]!=arr[start])
          {
            digits2=array_size-ii;
            break;
          }
        }

        for(ll ii{arr.size()-1};ii>=0;ii--)
        {
          if(arr[arr.size()-1]!=arr[ii])
          {
            digits3=ii+1;
            break;
          }
        }
        if(array_size%2==0)
        {
          while(l<h)
          {
            if(arr[l]!=arr[h])
            {
              digits1=h-l+1;
              break;
            }
            l++;
            h--;
          }
        }
        else 
        {
          std::vector <ll> counts{}; 
          std::vector <ll> elements{arr};
          for(auto k:arr)
          {
            counts.push_back(countelement(arr,k));
          }
          VectorDisplay(arr);
        }
        
        ll min1{min(digits3,digits2)};
        cout<<"Case: "<<i<<" digits1: "<<digits1<<" digits2: "<<digits2<<" digits3: "<<digits3<<endl;
        cout<<min(digits1,min1)<<endl;
       
  }

  return 0;
}
