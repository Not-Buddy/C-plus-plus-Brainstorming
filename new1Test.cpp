#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
struct Card
{
  int face;
  int shape;
  int color;
};
struct Rectangle
{
  int length;
  int breadth;
};
struct Rectangle r1={10,5};
int main(){
  struct Card deck[5]={{1,2,3}};
  printf("Face attrtibute of the cards structure: %d\n",deck[0].face);
  printf("Shape attribute of the cards structure: %d\n",deck[0].shape);
  printf("Size of the whole structure: %d\n",sizeof(r1));
  cout<<"Length of the Rectangle in Structure: "<<r1.length<<endl;
  cout<<"Breadth of the Rectangle in Structure: "<<r1.breadth<<endl;

}
