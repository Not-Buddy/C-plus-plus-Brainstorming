
#include  <iostream>
using namespace std;
void fun(int n)
{
  if(n>0)
  {
    fun(n-1);
    cout<<n<<"\n";
  }
}
int main()
{
  fun(3); //Prints 1,2,3          
  return 0;
}
