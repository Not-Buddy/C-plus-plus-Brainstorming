#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class Player
{
  private:
    std::string name;
    int level;
    int exp;
  public:
    Player(std::string name="None",int level=0,int exp=0);
    std::string get_name(){return name;}
    int get_exp(){return exp;}
    int get_level(){return level;}
    
    //Copy constructor
    Player(const Player &source);

    ~Player(){cout<<"Destructor called for:"<<name<<endl;}
};

  Player::Player(const Player &source)
    :Player(source.name,source.level,source.exp)
{
  cout<<"Copy constructor -made copy: "<<source.name<<endl;
}


Player::Player(std::string name_val,int level_val,int exp_val)
  :name{name_val},level{level_val},exp{exp_val}
{

}
//Player::std::string name get_name(){return name}
//Player::int get_level(){return level}
//Player::int get_exp(){return exp}
void display_player(Player p)
{
  cout<<p.get_name()<<endl;
  cout<<p.get_level()<<endl;
  cout<<p.get_exp()<<endl;
}
int main()
{
  Player aary{"Aary Kinge",1,2};
  display_player(aary);
  return 0;
}
