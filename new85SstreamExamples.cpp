#include <iostream>
#include <sstream>

int main() {
    std::string input = "47|53";
    std::stringstream ss(input);

    int a, b;
    char separator;

    ss >> a >> separator >> b;

    std::cout << "a: " << a << "\n";
    std::cout << "separator: " << separator << "\n";
    std::cout << "b: " << b << "\n";

    return 0;
}

