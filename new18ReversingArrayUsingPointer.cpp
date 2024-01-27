#include <iostream>
using namespace std;

void printArr(int *A,int ArrSize)
{
  cout<<"Printing Array :\n";
  for(size_t i{0};i<ArrSize;i++)
  {
    cout<<*(A+i)<<endl;
  }
}
void swap(int &a,int &b)
{
  int c;
  c=a;
  a=b;
  b=c;
}
void reverse(int *A,int ArrSize,int *ptr)
{

  int j=ArrSize-1;
  printArr(ptr,5);
  for(size_t i{0};i<ArrSize/2;i++,j--)
  {
    if(i==j)
      break;
    swap(A[i],A[j]);
    //cout<<A[i]<<" "<<A[j]<<endl;
  }
  printArr(ptr,5);

}


int main()
{
  int A[5]={1,2,3,45,5};
  int *ptr=A;
  reverse(A,5,ptr);
}

