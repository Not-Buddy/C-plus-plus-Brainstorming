#include <iostream>
using namespace std;
int Factorial(int n)
{
  int Fac{};
  if(n==0)
    return 1;
  else {
    return n*Factorial(n-1);
  }
}
int main()
{
  int n{};
  cout<<"Enter the number of which you want to find out factorial for: "<<"\n";
  cin>>n;
  cout<<"The Factorial is: "<<Factorial(n);

  return 0;
}
