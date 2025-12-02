#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void shiftL(int number_rotated, int &lock)
{
    int remaining = number_rotated % 100;
    lock -= remaining;
    if(lock < 0)
        lock += 100;
}

void shiftR(int number_rotated, int &lock)
{
    int remaining = number_rotated % 100;
    lock = (lock + remaining) % 100;
}

int main()
{
    // Read from file instead of cin
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input.txt\n";
        return 1;
    }
    
    int lock = 50;
    int zeros = 0;
    string input;
    
    while(getline(inputFile, input))
    {
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        
        if (input.size() < 2) 
            continue;
        
        int number_rotated = stoi(input.substr(1));
        
        if(input[0] == 'L')
            shiftL(number_rotated, lock);
        else if(input[0] == 'R')
            shiftR(number_rotated, lock);
        
        if(lock == 0)
            zeros++;
    }
    
    inputFile.close();
    cout << zeros << "\n";
    return 0;
}

