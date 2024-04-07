#include <iostream>
#include <vector>
#include <algorithm> // for std::remove

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 3, 5, 3};

    // Element to delete
    int elementToDelete = 3;

    // Remove all occurrences of the element
    vec.erase(std::remove(vec.begin(), vec.end(), elementToDelete), vec.end());

    // Output the vector after deletion
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

