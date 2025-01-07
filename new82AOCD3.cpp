#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

void vectormaker(std::vector <int>&vec1,std::string input)
{
  std::string digit{};
  for(int i{0};i<input.size();i++)
  {
    while(std::isdigit(input[i]))
    {
      digit.push_back(input[i]);
      i++;
    }
    vec1.push_back(std::stoi(digit));

    digit.clear();
  }
}

bool isAscending(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isDescending(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > vec[i - 1]) {
            return false;
        }
    }
    return true;
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
    long long Total{};
    while (std::getline(inputFile,line)) 
    {
      for(int i{0};i<line.size()-4;i++)
      {
        string slice=line.substr(i,4);
        if(slice=="mul(")
        {
          i=i+4;
          //TakeFirstDigit till , TakeSecondDigit till )
          std::string Num1{},Num2{};
          while(line[i]!=',')
          {
            Num1.push_back(line[i]);
            i++;
          }
          if(Num1.size()>3)
          {
            i=i-Num1.size()+1;
            Num1.clear();
          }
          
          i++;
          while(line[i]!=')')
          {
            Num2.push_back(line[i]);
            i++;
          }
          if(Num2.size()>3)
          {
            i=i-Num2.size()+1;
            Num2.clear();
          }
          if(Num1.empty()||Num2.empty())
          {
            Num1.push_back('0');
            Num2.push_back('0');
          }
            int n1=stoi(Num1);
            int n2=stoi(Num2);
            Total=n1*n2;
          cout<<Num1<<" "<<Num2<<endl;
        }
      }
    }
    cout<<"This is the total:- "<<Total<<endl;
    //176
    inputFile.close();
  return 0;
}
