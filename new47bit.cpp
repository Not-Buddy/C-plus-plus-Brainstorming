#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  int lines{},x{};
  std::string inval{};
  cin>>lines;
  cin.ignore();
  for(int i{0};i<lines;i++)
  {
    getline(cin,inval);
    if(inval=="X++"||inval=="++X")
    {
      x++;
    }
    else
    {
      x--;
    }
  }
  cout<<x<<"\n";

  return 0;
}
