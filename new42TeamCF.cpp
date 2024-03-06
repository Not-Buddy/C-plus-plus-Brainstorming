#include <iostream>
#include <string>
using namespace std;
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  int sum_solved{};
  for(int i{0};i<testcases;i++)
  {
    int j{},k{},l{};
    cin>>j>>k>>l;
    if(j+k+l>1)
    {
      sum_solved++;
    }
  }
  cout<<sum_solved;

  return 0;
}
