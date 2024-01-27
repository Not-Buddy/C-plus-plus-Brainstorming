#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
vector <int> uncheckeddata{};
int IntVal(std::string strung,int &n)
{
  int index, value{},toint{};
  std::string accumulator{};
  for(n;std::isdigit(static_cast<unsigned char>(strung[n]));n++)
  {
    accumulator.push_back(strung[n]);  
  }
  toint=std::stoi(accumulator);
  
  return toint;
}


int main () {
  // Create a text file

  // Create a text string, which is used to output the text file
  string myText;
  vector <std::string> input{};

  // Read from the text file
  ifstream MyReadFile("input.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) 
  {
    // Output the text from the file
    //cout << myText;
    input.push_back(myText);
  }
  for(std::string c:input)
  {
    //cout<<c<<"\n";
    int dynamicvalue{};
    for(int i{0};i<c.size();i++)
    {
      if(std::isdigit(static_cast<unsigned char>(c[i])))
      {
        //intvalue[k].push_back(c1);
        dynamicvalue=IntVal(c,i);  
        uncheckeddata.push_back(dynamicvalue);
        cout<<dynamicvalue<<endl;
      }
    }
    
  }

  // Close the file
  MyReadFile.close();
}
