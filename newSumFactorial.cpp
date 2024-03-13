#include <iostream>
typedef unsigned long long ll;
ll factorial_sum(ll input)
{
  ll sum{0};
  for(ll i{1};i<=input;i++)
  {
    sum+=i;
  }
  return sum;
}
using namespace std;
int main()
{
  
  ll input{},sumfac{};
  
  cin>>input;
  sumfac=factorial_sum(input);
  cout<<"The SumFac of "<<input<<" is :"<<sumfac<<endl;
  return 0;
}
