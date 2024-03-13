#include <iostream>
using namespace std;
typedef unsigned long long ll;
int main()
{
  ll testcases{};
  cin>>testcases;
  cin.ignore();
  for(ll i{0};i<testcases;i++)
  {
    int elo{};
    cin>>elo;
    cin.ignore();
    if(elo<1400)
    {
      cout<<"Division 4"<<endl;
    }
    else if(elo<1600)
    {
      cout<<"Division 3"<<endl;
    }
    else if(elo<1900)
    {
      cout<<"Division 2"<<endl;
    }
    else 
    {
      cout<<"Division 1"<<endl;
    }
  }

  return 0;
}
