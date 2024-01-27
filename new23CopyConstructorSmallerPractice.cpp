#include <iostream>
#include <string>
using namespace std;
class Dog
{
  private:
    std::string name;
    int age;
    bool genderMale;
  public:
    Dog(std::string name="None",int age=0,bool genderMale=0);
    //copy constructor
    Dog(const Dog &source);
    std::string get_name(){return name;}
    int get_age(){return age;}
    bool get_genderMale(){return genderMale;}
    ~Dog(){cout<<"Destructor Called"<<endl;}
};
Dog::Dog(const Dog &source)
      :Dog(source.name,source.age,source.genderMale)
    {

    }
Dog::Dog(std::string name_val,int age_val,bool genderMale_val)
  :name{name_val},age{age_val},genderMale{genderMale_val}
{

}
void display(Dog d)
{
  cout<<d.get_name()<<"\n";
  cout<<d.get_age()<<"\n";
  cout<<d.get_genderMale()<<"\n";
}
int main()
{
  Dog Nobody{"TheDawg",5,1};
  display(Nobody);
  return 0;
}
