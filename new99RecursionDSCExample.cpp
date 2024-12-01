#include <iostream>
using namespace std;
void recur(int a)
{
  if(a==0)
    return a;
  recur(a-1);
}
int main()
{
  int a{10};
}
