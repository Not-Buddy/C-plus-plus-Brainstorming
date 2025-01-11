#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // For std::pair
#include <sstream> // For std::stringstream
using namespace std;

void CheckUpdates(std::vector<std::pair<int, int>> Rules 
    ,std::vector<int> sequence, bool &Boo,int &ToAdd)
{
  for(int i{0};i<Rules.size();i++)
  {
    auto it1=std::find(sequence.begin(),sequence.end()
        ,Rules[i].first);
    auto it2=std::find(sequence.begin(),sequence.end()
        ,Rules[i].second);
    if(indexA!=sequence.end()||indexB!=sequence.end())
    {
      int indexA=it1-sequence.begin();
      int indexB=it2-sequence.begin();
      if(indexA>indexB)
      {

      }
    }
     cout<<"IndexA: "<<indexA<<" IndexB: "<<indexB<<endl;
  }
  if(Boo=true)
  {
    int midIndex = sequence.size()/2;
    ToAdd=sequence[midIndex];
  }
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file 'InputFile'\n";
        return 1;
    }

    std::vector<std::pair<int, int>> Rules;
    std::vector<std::vector<int>> sequences;
    int Total;

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
                Rules.emplace_back(a, b);
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

    for(int k{0};k<sequences.size();k++)
    {
      bool Boo=true;
      int ToAdd;
      CheckUpdates(Rules,sequences[k],Boo,ToAdd);
      Total+=ToAdd;
    }

    cout<<"Total is : "<<Total<<endl;

    inputFile.close();

    // Output the data for verification

    return 0;
}

