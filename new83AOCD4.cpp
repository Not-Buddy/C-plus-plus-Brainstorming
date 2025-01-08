#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int RightLeft(std::vector<std::string> Input)
{
  int Count{};
  for(int i{0};i<Input.size();i++)
  {
    for(int j{0};j<Input[i].size()-4;j++)
    {
      if(Input[i].substr(j,4)=="XMAS")
      {
        cout<<Input[i].substr(j,4);
        Count++;
      }
    }
  }
  for(int i{0};i<Input.size();i++)
  {
    std::reverse(Input[i].begin(),Input[i].end());
    for(int j{0};j<Input[i].size()-4;j++)
    {
      if(Input[i].substr(j,4)=="XMAS")
      {
        cout<<Input[i].substr(j,4);
        Count++;
      }
    }
  }
  return Count;
}

int UpDown(std::vector<std::string> Input)
{
  int Count{};
  
  for(int i{0};i<Input.size()-4;i++)
  {
    for(int j{0};j<Input[i].size();j++)
    {
      std::string CheckThis{};
      for (int k = 0; k < 4; k++)//Building String 
      {
       CheckThis += Input[i + k][j];
      }

      if(CheckThis == "XMAS") 
      {
        std::cout << CheckThis;
        Count++;
      }

      std::reverse(CheckThis.begin(),CheckThis.end());

      if(CheckThis == "XMAS") 
      {
        std::cout << CheckThis;
        Count++;
      }
    }
  }
  return Count;
}


int main()
{
  std::ifstream inputFile("input.txt");

    if(!inputFile) 
    {
        std::cerr << "Error: Could not open the file 'input.txt'." << std::endl;
        return 1;
    }

    std::string line{};
    int Total{};
    std::vector<std::string> Input{};
    while (std::getline(inputFile,line)) 
    {
     Input.push_back(line); 
    }
    Total=RightLeft(Input); 
    Total+=UpDown(Input);
    cout<<"RL: "<<Total<<endl;
    //176
    inputFile.close();
  return 0;
}
