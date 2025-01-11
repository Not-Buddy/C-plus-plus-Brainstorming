#include <iostream>
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
          if(!Num1.empty())
          {
            while(line[i]!=')')
            {
              Num2.push_back(line[i]);
              i++;
            }
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
            long Mult{};
            int n1=stoi(Num1);
            int n2=stoi(Num2);
            Mult=n1*n2;
            Total+=Mult;
          cout<<Num1<<" "<<Num2<<endl;
        }
      }
    }
    cout<<"This is the total:- "<<Total<<endl;
    //176
    inputFile.close();
  return 0;
}
