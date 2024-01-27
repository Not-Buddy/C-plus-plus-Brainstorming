#include <iostream>
using namespace std;
int pow(int m,int n)
  {
   if(n==0)
     return 1;
   else {
    return m*pow(m,n-1);
   }

  }
int main()
  {
    int n{},p{},out{};
    cout<<"Enter the number for which you want to find exponent for: "<<"\n";
    cin>>n;
    cout<<"Enter the exponent power: "<<"\n";
    cin>>p;
    out=pow(n,p);
    cout<<"The Output is : "<<out<<"\n";
    return 0;
  }
