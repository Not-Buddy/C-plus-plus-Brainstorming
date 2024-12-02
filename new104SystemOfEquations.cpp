#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

void countAPair(int n, int &count)
{
  int a,b;
  for(int a{0};a<=n;a++)
  {
    for(int b{0};b<=n;b++)
    {
      if(n==a*a+b)
        count++;
    }
  }
}
void countBPair(int m, int &count)
{
  int a,b;
  for(int a{0};a<=m;a++)
  {
    for(int b{0};b<=m;b++)
    {
      if(m==b*b+a)
        count++;
    }
  }
}
int main()
{
  int n{},m{};

  cin>>n>>m;
  cin.ignore();
  int countA{},countB{};
  countAPair(n,countA);
  countBPair(m,countB);
  cout<<countA+countB<<endl;


  return 0;
}
