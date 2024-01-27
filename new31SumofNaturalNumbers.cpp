#include <iostream>
using namespace std;
int SumNatural(int n)
{
  if(n>0)
    return n+SumNatural(n-1);
  else 
    return 0;
}
int main()
{
  int n{};
  cout<<"Enter the natural number for which you want to find out sum for:";
  cin>>n;

  cout<<"The sum of the natural naumber upto "<<n<<
    " is: "<<SumNatural(n);
  return 0;
}
