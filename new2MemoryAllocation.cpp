#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
  int a=10;
  int *p,*q;
  
  p=(int*)malloc(5*sizeof(int)); //Memory allocation Using just c
  q=new int[5]; //Memory allocation Using c++ 
  cout<<"This is accessed directly :"<<a<<endl;
  cout<<"This is accessed using pointed :"<<*p<<endl;
  delete [ ]q;
  free(p); 
  return 0;
}
