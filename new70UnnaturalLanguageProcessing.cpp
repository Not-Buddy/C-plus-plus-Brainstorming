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
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    int length{};
    std::string input{};
    cin>>length;
    cin.ignore();
    getline(cin,input);
    //C b,c,d 
    //V a,e
    //CV CVC
    // ba ca da be ce de 
    // bab cac dad 
    // beb cec ded 
    // bac cab 

    
 //   for(int ii{0};ii<input.size()-2;ii++)
   // {
    //  for(char C:{'b','c','d'})
     // {
      //  for(char V:{'a','e'})
       // {
        //  for(char C1:{'b','c','d'})
         // {
          //  std::string compare{};
           // compare.push_back(C);
            //compare.push_back(V);
            //compare.push_back(C1);
            //if(compare==input.substr(ii,3)&&input[ii+3]!='\0')
             // input.insert(ii+3,1,'.');
          //}
        //}
    //  }
   // }
    std::string res{};
    while(!input.empty())
    {
      int x;
      if(input.back()=='a'||input.back()=='e'){x=2;}
      else {x=3;}
      while(x--)
      {
        res+=input.back();
        input.pop_back();
      }
      res+='.';
    }
    res.pop_back();
    reverse(res.begin(),res.end());
    cout<<res<<endl;




  }

  return 0;
}
