#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

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
    sort(vector1.begin(),vector1.end());
    sort(vector2.begin(),vector2.end());

    inputFile.close();
    int sum{};
    for(int i{0};i<vector1.size();i++)
    {
      vec3.push_back(abs(vector1[i]-vector2[i]));
      sum+=abs(vector1[i]-vector2[i]);
    }
    for(auto Lol:vec3)
    {
      cout<<Lol<<endl;
    }
    std::cout<<"The sum is:"<<sum<<std::endl;
    


    return 0;
}

