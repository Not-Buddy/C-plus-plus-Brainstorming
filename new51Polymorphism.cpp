#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;
  //Compile time polymorphism
  //Function Overloading and Operator Overloading
  //
  //Run time polymorphism 
  //Function Overloading
  //Simple example 
  //Account a;
  //a.withdraw(1000); Accont::withdraw()
  //
  //Savings b;
  //b.withdraw(1000); Savings::withdraw()
  //
  //Accont *p= new Trust();
  //P->withdraw(1000); This will call Account::withdraw() instead of Trust::withdraw();
  //This happens without Dyamic Binding 
  //
  //
  //
  class Base
  {
    public:
      void say_hello()const
      {std::cout<<"Hello - I am a Base class object"<<std::endl; }
  };
  class Derived:public Base
  {
    public:
      void say_hello() const
      {std::cout<<"Hello - I am Derived class object"<<std::endl;}
  };

  void greetings (const Base &obj)
  {
    std::cout<<"Greetings: ";
    obj.say_hello();
  }
int main()
{
  Base a;
  a.say_hello();

  Derived d;
  d.say_hello();
  
  greetings(a);
  greetings(d);

  Base *ptr=new Derived();
  ptr->say_hello();
  
  std::unique_ptr<Base> ptr1=std::make_unique<Derived>();
  ptr1->say_hello();
  greetings(a);
  delete ptr;

  return 0;
}

