#include <iostream>
using namespace std;
int add(int a,int b)
{
  int dsum;
  dsum=a+b;
  return dsum;
}
int main()
{
  int num1=10,num2=20,sum;
  sum=add(num1,num2);
  cout<<"The sum of the num1 "<<num1<<" and num2 "<<num2<<endl<<"is : "<<sum<<endl;
}
