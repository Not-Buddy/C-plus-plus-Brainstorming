#include <iostream>
using namespace std;
struct Rectangle{
  int length;
  int breadth;
};
void fun(struct Rectangle &r)
{
  cout<<"Length Inside Function:"<<r.length<<endl<<"Breadth Inside Function:"<<r.breadth<<endl;
  r.length=r.length+2;
  r.breadth=r.breadth+2;
}
int main()
{
  struct Rectangle r={10,5};
  fun(r);
  cout<<"Length: "<<r.length<<"\nBreadth: "<<r.breadth<<endl;
  return 0;
}
