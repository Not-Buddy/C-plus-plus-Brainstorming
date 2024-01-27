#include <iostream>
using namespace std;
struct Array
{
  int *A;
  int size;
  int length;
};
int main()
{
  int *A;
  struct Array arr;
  cout<<"Enter size of an array: "<<endl;
  cin>>&arr.size;
  arr.A=new int[size];

  
  return 0;
}
