#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Mystring
{
  private:
    char *str;
  public:
    Mystring();
    Mystring(const char *c);
    Mystring (const Mystring &source);
    ~Mystring();
    void display() const;
    int get_length() const;
    const char *get_str() const;
};
Mystring::Mystring()
  :str{nullptr}{
    str=new char[1];
    *str='\0';
    }

Mystring::Mystring(const char *s)
  :str{nullptr}
{
  if(s==nullptr){
    str=new char[1];
  }
  else{
    str=new char[std::strlen(s)+1];
    std::strcpy(str,s);
  }
}

Mystring::Mystring(const Mystring &source)
  :str{nullptr}{
    str=new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}

Mystring::~Mystring(){
  delete [] str;
}

Mystring &Mystring::operator=(const Mystring &rhs)
{
  std::cout<<"Copy assignment"<<std::endl;
  if(this==&rhs)
    return *this;
  delete [] this ->str;
  str=new char[stdLLstrlen(rhs.str)+1];
  std::strcpy(this->str,rhs.str);
  return *this;
}

void Mystring::display() const{
  std::cout<<str<<":"<<get_length()<<std::endl;
}

int Mystring::get_length() const {return std::strlen(str);}

const char *Mystring::get_str() const { return str;}

int main()
{
  Mystring empty;
  Mystring larry("Larry");
  Mystring stooge{larry};

  empty.display();
  larry.display();
  stooge.display();

  return 0;
}
