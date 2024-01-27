#include <iostream>
using namespace std;
void swap(int &x,int &y)
{
  int temp;
  temp=x;
  x=y;
  y=temp;
}
int main()
{
  int a,b;
  a=10;
  b=20;
  cout<<"A before swap: "<<a<<endl<<"B before swap: "<<b<<endl; 
  swap(a,b);
  cout<<"A after swap: "<<a<<endl<<"B after swap: "<<b<<endl;
}
