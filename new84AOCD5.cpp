#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // For std::pair
#include <sstream> // For std::stringstream

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file 'InputFile'\n";
        return 1;
    }

    std::vector<std::pair<int, int>> InputMap;
    std::vector<std::vector<int>> sequences;

    std::string line;
    while (std::getline(inputFile, line)) 
    {
        if (line.find('|') != std::string::npos) 
        {
            // Process pair data
            int a, b;
            char separator;
            std::stringstream ss(line);
            ss >> a >> separator >> b;
            if (separator == '|')
            {
                InputMap.emplace_back(a, b);
            }
        } 
        else if (line.find(',') != std::string::npos) 
        {
            // Process sequence data
            std::vector<int> sequence;
            int num;
            char separator;
            std::stringstream ss(line);
            while (ss >> num) 
            {
                sequence.push_back(num);
                ss >> separator; // Consume the comma
            }
            sequences.push_back(sequence);
        }
    }

    inputFile.close();

    // Output the data for verification

    return 0;
}

