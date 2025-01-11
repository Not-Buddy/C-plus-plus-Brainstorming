#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;
int main()
{
  std::ifstream inputFile("input2.txt");

    if(!inputFile) 
    {
        std::cerr << "Error: Could not open the file 'input.txt'." << std::endl;
        return 1;
    }

    std::string line{};
    long long Total{};
    std::vector<std::string> Map{};

    while (std::getline(inputFile,line)) 
    {
      Map.push_back(line);
    }
    
    int x{},y{};
    for(int i{0};i<Map.size();i++)
    {
      auto it = std::find(Map[i].begin(),Map[i].end(),'^');
      if(it!=Map[i].end())
      {
        x=i;
        y=std::distance(Map[i].begin(),it);
      }
    }
    cout<<"X: "<<x<<" Y: "<<y<<endl;

    std::set <std::pair<int,int>> Visited{};
    
//Leaving the mapped area conditions
//Map.size()>x Map[i].size()>y
//x<0 y<0
  int j{0};
  while(true)
  {
    if(x>Map.size()||y>Map[0].size()||x<0||y<0)
      break;
    if(j>3)
      j=0;
    switch(j)
    {
      case 0:
        while(Map[x][y]!='*')
        {
          Visited.insert(make_pair(x,y));
          x--;
        }
        break;
      case 1: 
        while(Map[x][y]!='*')
        {
          Visited.insert(make_pair(x,y));
          y++;
        }
        break;
      case 2: 
        while(Map[x][y]!='*')
        {
          Visited.insert(make_pair(x,y));
          x++;
        }
        break;
      case 3: 
        while(Map[x][y]!='*')
        {
          Visited.insert(make_pair(x,y));
          y--;
        }
        break;
      j++;
    }
  }
    
  for(auto P:Visited)
  {
    cout<<"First: "<<P.first<<" Second :"<<P.second;
  }



    cout<<"This is the total:- "<<Total<<endl;
    //176
    inputFile.close();
  return 0;
}
