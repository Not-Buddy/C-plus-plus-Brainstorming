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
    for(int j{0};j<Input[i].size()-3;j++)
    {
      if(Input[i].substr(j,4)=="XMAS")
      {
        Count++;
      }
    }
  }
  for(int i{0};i<Input.size();i++)
  {
    std::reverse(Input[i].begin(),Input[i].end());
    for(int j{0};j<Input[i].size()-3;j++)
    {
      if(Input[i].substr(j,4)=="XMAS")
      {
        Count++;
      }
    }
  }
  return Count;
}

int UpDown(std::vector<std::string> Input)
{
  int Count{};
  
  for(int i{0};i<Input.size()-3;i++)
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
        Count++;
      }

      std::reverse(CheckThis.begin(),CheckThis.end());

      if(CheckThis == "XMAS") 
      {
        Count++;
      }
    }
  }
  return Count;
}

int CrissCross(std::vector <std::string> Input)
{
  int Count{};
  
  for(int i{0};i<Input.size()-3;i++)
  {
    for(int j{0};j<Input[i].size()-3;j++)
    {
      std::string CheckThis{};
          CheckThis.push_back(Input[i][j]);
          CheckThis.push_back(Input[i+1][j+1]);
          CheckThis.push_back(Input[i+2][j+2]);
          CheckThis.push_back(Input[i+3][j+3]);
          cout<<"RightDiag: "<<CheckThis<<endl;
        if(CheckThis=="XMAS"||CheckThis=="SAMX")
          Count++;
    }
  }

  for(int i{0};i<Input.size()-3;i++)
  {
    for(int j{3};j<Input[i].size();j++)
    {
      std::string CheckThis{};
          CheckThis.push_back(Input[i][j]);
          CheckThis.push_back(Input[i+1][j-1]);
          CheckThis.push_back(Input[i+2][j-2]);
          CheckThis.push_back(Input[i+3][j-3]);
          cout<<"LeftDiag: "<<CheckThis<<endl;
        if(CheckThis=="XMAS"||CheckThis=="SAMX")
          Count++;
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
      int a = RightLeft(Input);
      int b = UpDown(Input);
      int c = CrissCross(Input);
    Total= a + b + c;
    cout<<"RightLeft: "<<a; 
    cout<<" UpDown: "<<b;
    cout<<" CrissCross: "<<c;
    cout<<" Total: "<<Total<<endl;
    cout<<endl;
    //176
    inputFile.close();
  return 0;
}
