#include <iostream>
#include <limits>

int main() {
    std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Maximum value for unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Maximum value for long: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "Maximum value for unsigned long: " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "Maximum value for long long: " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "Maximum value for unsigned long long: " << std::numeric_limits<unsigned long long>::max() << std::endl;
    
    return 0;
}

