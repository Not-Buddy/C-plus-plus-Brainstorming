#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

void rec(int i,long long sum,long long target, const vector <int>&v)
{
  if(i==(int)v.size())
  {
    if(sum==target)
    {
      ok=true;
      return;
    }
  }
  rec(i+1,sum+v[i],target,v,ok);
  rec(i+1,sum*v[i],target,v,ok);
}



int main()
{
  std::ifstream inputFile("input.txt");

    if(!inputFile) 
    {
        std::cerr << "Error: Could not open the file 'input.txt'." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<long long> test_val{};
    std::vector<std::vector<long long>> eqns{};
    int i{0};
    while(std::getline(inputFile,line))
    {
      long long test;
      bool OK;
      char Colon;
      std::istringstream iss(line);
      iss>>test>>Colon;
      long long temp{};
      cout<<test<<Colon;
      test_val.push_back(test);
      std::vector<long long> eqn{};
      while(iss>>temp)
      {
        eqn.push_back(temp);
        std::cout<<temp<<" ";
      }
      eqns.push_back(eqn);
      cout<<" "<<i<<endl;
      i++;


      for(int j{0};j<eqns[i].size();j++)
      {
        
      }
      

    }

    inputFile.close();
  return 0;
}
