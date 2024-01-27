#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int a=10;
  int &r=a;
  cout<<"a: "<<a<<endl;
  cout<<"r++: "<<r++<<endl;
  cout<<"r: "<<r<<endl;
  cout<<"a: "<<a<<endl;
  return 0;
}
