#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Account
{
  public:
  void withdraw(int i)
    {
      cout<<"Withdraw Account"<<endl;
    }
};
class Checking: public Account
{
  public:
  void withdraw(int i)
    {
      cout<<"Withdraw Checking"<<endl;
    }
};
class Savings: public Account
{
  public:
  void withdraw(int i)
    {
      cout<<"Withdraw Savings"<<endl;
    }
};
class Trust: public Account
{
  public:
  void withdraw(int i)
    {
      cout<<"Withdraw Trust"<<endl;
    }
};



int main()
{
  std::cout<<"\n===Pointers==="<<std::endl;
  Account *p1=new Account();
  Account *p2=new Savings();
  Account *p3=new Checking();
  Account *p4=new Trust();

  p1->withdraw(1000);
  p2->withdraw(1000);
  p3->withdraw(1000);
  p4->withdraw(1000);
  
  std::cout<<"\n===Array==="<<std::endl;
  Account *array[]={p1,p2,p3,p4};
  for(auto i=0;i<4;i++)
  {
    array[i]->withdraw(1000);
  }

  std::cout<<"\n==Clean up=="<<std::endl;
  delete p1;
  delete p2;
  delete p3;
  delete p4;
  
  return 0;
}
