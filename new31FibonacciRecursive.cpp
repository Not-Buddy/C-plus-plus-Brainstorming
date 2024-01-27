#include <iostream>
using namespace std;
double Fibo(int n)
{
  if(n<=1)
    return n;
  return fib(n-2)+fib(n-1);
}
int main()
{
  int n{30};
  cout<<Fibo(30);
  return 0;
}
