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

    if (!inputFile) {
        std::cerr << "Error: Could not open the file 'input.txt'." << std::endl;
        return 1;
    }

    std::string line{};
    int tot{};
    while (std::getline(inputFile,line)) 
    {
      std::vector<int> numbers;
      vectormaker(numbers,line);
      bool safe=1;
      bool asc,dsc;
      asc=isAscending(numbers);
      dsc=isDescending(numbers);
      if(asc||dsc)
      {
        for(int i{0};i<numbers.size()-1;i++)
        {
           int diff=abs(numbers[i]-numbers[i+1]);
           if(diff>3||diff<1)
            {
              safe=0;
              break;
            }
        }
      }
      else 
      {
        safe=0;
      }
      if(safe==1)
      {
        cout<<"Safe: ";
        for(auto Lol:numbers)
        {
          cout<<Lol<<" ";
        }
        cout<<endl;
        tot++;
      }
    }
    cout<<tot<<endl;
    //393
    //176
    inputFile.close();
  return 0;
}
