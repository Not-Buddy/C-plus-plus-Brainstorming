#include <iostream>
typedef unsigned long long ll;
using namespace std;
int main()
{
  int t{};
  cin>>t;
  cin.ignore();
  for(int i{1};i<=t;i++)
  {
    ll y{},x{},num{};
    cin>>y>>x;
    cin.ignore();
    if(x>=y)
    {
      if(x%2==0)
        num=x*x+1+y-1;
      else 
        num=x*x-y+1;
    }
    else 
    {
      if(y%2==0)
        num=y*y-x+1;
      else 
        num=(y-1)*(y-1)+1+x-1;
    }
    cout<<num<<endl;
  }

  return 0;
}
