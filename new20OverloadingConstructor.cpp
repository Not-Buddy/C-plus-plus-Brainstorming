#include <iostream>
#include <string>
using namespace std;
class Player
{
  private:
    std::string name;
    int health;
    int xp;
  public:
    //Player();
    //Player(std::string name_val);
    Player(std::string name_val="None",int health_val=0,int xp_val=0);
};
//Player::Player()
  //:Player{"None",0,0}
//{
  //cout<<"No-args constructor"<<endl;
  //name="None";
  //health=0;
  //xp=0;
//}
//Player::Player(std::string name_val)
  //:Player{name_val,0,0}
  //:name{name_val},health{0},xp{0}
//{
  //cout<<"one-args constructor"<<endl;
 // name=name_val;
  //health=0;
//xp=0;
//}
Player::Player(std::string name_val, int health_val,int xp_val)
  :name{name_val},health{health_val},xp{xp_val}
  //:name{name_val},health{health_val},xp{xp_val}
{
  cout<<"3-args constructor"<<endl;
 // name =name_val;
//  health=health_val;
  //xp=xp_val;
}
int main()
{
  Player empty;
  Player hero {"Hero",100};
  Player villain {"Villain"};
  Player frank{"Frank",100,4};
  Player *enemy=new Player("Enemy",1000,0);
  delete enemy;
  return 0;
}
