#include <iostream>
using namespace std;
int fun(int n)
{
  if(n>100)
  {
    cout<<n<<"\n";
   return n-10; 
  }
  else 
  {
    cout<<n<<"\n";
    return fun(fun(n+11));
  }
}



int main()
{
  cout<<fun(95);
  return 0;
}
