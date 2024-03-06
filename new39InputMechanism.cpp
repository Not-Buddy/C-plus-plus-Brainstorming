#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::cout << "Enter integers separated by spaces: ";
    std::getline(std::cin, input);
    std::istringstream iss(input); // Creating an input string stream
    std::vector<int> integers;
    int num;
    while (iss >> num) {
        integers.push_back(num);
    }
    std::cout << "Integers: ";
    for (int i : integers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

