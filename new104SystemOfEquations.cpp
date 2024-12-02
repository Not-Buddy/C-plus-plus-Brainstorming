#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

void countAPair(int n,int m, int &count)
{
  int a,b;
  for(int a{0};a<=n+m;a++)
  {
    for(int b{0};b<=n+m;b++)
    {
      if((n==a*a+b)&&(m==b*b+a))
        count++;
    }
  }
}
int main()
{
  int n{},m{};

  cin>>n>>m;
  cin.ignore();
  int countA{};
  countAPair(n,m,countA);
  cout<<countA<<endl;


  return 0;
}
