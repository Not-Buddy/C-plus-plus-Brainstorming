#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
typedef unsigned long long ll;
using namespace std;
//12 18
//4 10
//

int hcf(int a, int b) 
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) 
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }    
    return a;
}

bool truegcd(int int1, int int2, int n) 
{
    int commonDivisor = hcf(int1, int2);

    if (commonDivisor >= 2 && commonDivisor <= n) 
    {
        return true;
    }

    return false;
}

int main()
{
  int testcases{};
  cin>>testcases;
  for(int i{0};i<testcases;i++)
  {
    int a{},b{},k{};
    cin>>a>>b>>k;
    int steps{};

      if((k>=a&&k>=b)||truegcd(a,b,k))
      {
        a=0;
        b=0;
        steps++;
      }
      else
      {
        steps+=2;
      }


    cout<<steps<<"\n";


  }

  return 0;
}
