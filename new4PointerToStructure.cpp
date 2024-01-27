#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct Rectangle
{
  int length,breadth;
};
 
int main()
{
  struct Rectangle r={10,5};
  struct Rectangle *p=&r;
  r.length=15;
  (*p).length=20;
  cout<<"Length changed to 20: "<<(*p).length<<endl;
  p->length=30;
  cout<<"Length changed to 30: "<<p->length<<endl;
}
