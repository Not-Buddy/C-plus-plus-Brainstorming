#include <iostream>
//Doesnt work :(
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

bool checkOrder(const vector<int>& arr) {
    int ascendingViolations = 0, descendingViolations = 0;

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) ++ascendingViolations;
        if (arr[i] < arr[i + 1]) ++descendingViolations;

        // If either violation count exceeds 1, it's bad
        if (ascendingViolations > 1 && descendingViolations > 1) return false;
    }

    if (ascendingViolations <= 1) return true;
    if (descendingViolations <= 1) return true;
    return false;
}

bool checkDifference(const vector<int>& numbers)
{
  for(int i{0};i<numbers.size()-1;i++)
  {
    int diff=abs(numbers[i]-numbers[i+1]);
    if(diff>3||diff<1)
    {
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
      bool Checked=checkOrder(numbers);
      bool Check2=checkDifference(numbers);
      if(Check2)
      {
        tot++;
        cout<<"Safe: ";
          for(auto lol:numbers)
          {
            cout<<lol<<" ";
          }
        cout<<endl;
      }

    }
    cout<<tot<<endl;
    //393
    //176
    inputFile.close();
  return 0;
}
