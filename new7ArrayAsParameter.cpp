#include <iostream>
using namespace std;
void printarr(int A[],int n)
{
  for(size_t i{0};i<n;i++)
  {
    cout<<A[i]<<endl;
  }
}
void add(int *A,int n)
{
  for(size_t i{0};i<n;i++)
  {
    *(A+i)=*(A+i)+1;
  }
}
int main()
{
  int A[5]={1,2,3,4,5};
  cout<<"Before add function:"<<endl;
  printarr(A,5);
  add(A,5);
  cout<<"After add function:"<<endl;
  printarr(A,5);
}
