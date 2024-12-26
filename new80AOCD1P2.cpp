#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int numberCounter(int const num, vector <int> vec)
{
  int count{};
  for(int i{0};i<vec.size();i++)
  {
    if(num==vec[i])
    {
      count++;
    }
  }
  return count;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open the file 'input.txt'." << std::endl;
        return 1;
    }

    std::vector<int> vector1, vector2, vec3;
    int num1, num2;

    while (inputFile >> num1 >> num2) {
        vector1.push_back(num1);
        vector2.push_back(num2);
    }

    inputFile.close();
    int sum{};
    for(int i{0};i<vector1.size();i++)
    {
      int count{};
      count=numberCounter(vector1[i],vector2);
      sum+=count*vector1[i];
      cout<<vector1[i]<<" counts: "<<count<<endl;
    }
    std::cout<<"The sum is:"<<sum<<std::endl;
    


    return 0;
}

