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
  std::ifstream inputFile("input.txt");

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
    std::pair<int,int> me{x,y};
    vector<pair<int,int>> dirs={{-1,0},{0,1},{1,0},{0,-1}};
    int dir = 0; 
    std::set <std::pair<int,int>> Visited{};
    
    while(true)
    {
      Visited.insert(me);
      int r2=me.first+dirs[dir].first;
      int c2=me.second+dirs[dir].second;
      if(!(0<=r2 && r2<Map.size() && 0<=c2 && c2<Map[0].size()))
      {
        break;
      }
      if(Map[r2][c2]=='.'||Map[r2][c2]=='^')
      {
        cout<<"Me: "<<r2<<","<<c2<<endl;
        me={r2,c2};
      }
      else 
      {
        dir=(dir+1)%4;
      }

    }







//        while (true) {
//        // Check boundary and obstacle conditions
//        if (x < 0 || x > Map.size() || y < 0 || y > Map[0].size()) {
//            break; // Out of bounds
//        }
//
//        if (Map[x+dx[direction]][y+dy[direction]] == '*') {
//            direction = (direction + 1) % 4; // Turn 90 degrees clockwise
//        } else {
//            // Mark the current position as visited
//            Visited.insert({x, y});
//
//            // Move in the current direction
//            x += dx[direction];
//            y += dy[direction];
//            continue;
//        }
//
//        // Turn and try again
//        x += dx[direction];
//        y += dy[direction];
//    }

    // Output the visited positions

    cout<<"Visited Size: "<<Visited.size()<<endl;

    
//Leaving the mapped area conditions
//Map.size()>x Map[i].size()>y
//x<0 y<0
//  int j{0};
//  while(true)
//  {
//    if(x>=Map.size()||y>=Map[0].size()||x<0||y<0)
//      break;
//    if(j>3)
//      j=0;
//    switch(j)
//    {
//      case 0:
//        while(x>=0&&x<Map.size()&&y>=0&&
//            y<Map[0].size()&&Map[x][y]!='*')
//        {
//          Visited.insert(make_pair(x,y));
//          x--;
//        }
//        break;
//      case 1: 
//        while(x>=0&&x<Map.size()&&y>=0&&
//            y<Map[0].size()&&Map[x][y]!='*')
//        {
//          Visited.insert(make_pair(x,y));
//          y++;
//        }
//        break;
//      case 2: 
//        while(x>=0&&x<Map.size()&&y>=0&&
//            y<Map[0].size()&&Map[x][y]!='*')
//        {
//          Visited.insert(make_pair(x,y));
//          x++;
//        }
//        break;
//      case 3: 
//        while(x>=0&&x<Map.size()&&y>=0&&
//            y<Map[0].size()&&Map[x][y]!='*')
//        {
//          Visited.insert(make_pair(x,y));
//          y--;
//        }
//        break;
//      j++;
//    }
//  }
//    
//  for(auto P:Visited)
//  {
//    cout<<"First: "<<P.first<<" Second :"<<P.second;
//  }
//  cout<<endl;
//
//  cout<<"Visited :"<<Visited.size()<<endl;

    //176
    inputFile.close();
  return 0;
}
