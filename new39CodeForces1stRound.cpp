
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <utility>
#include <unordered_map>
#include <cctype>
using namespace std;

int main () {
  // Create a text file

  // Create a text string, which is used to output the text file
  string myText;
  vector <std::string> input{};
  int sum{0};

  // Read from the text file
  ifstream MyReadFile("input.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) 
  {
    // Output the text from the file
    //cout << myText;
    input.push_back(myText);
  }
  for(auto i:input)
    {
      cout<<i<<endl;
    }
  // Close the file
  MyReadFile.close();
}
