#include <iostream>
using namespace std;
int fun(int n)
{
  static int x=0;
  //Static variables get alloted space in the 
  //Code section 
  if(n>0)
  {
    x++;
    return fun(n-1)+x;
  }
return 0;
}
int main()
{
  int a=5;
  cout<<fun(a)<<"\n";
  return 0;
}
