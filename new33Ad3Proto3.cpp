#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
#include <utility>
#include <cctype>
using namespace std;
vector <std::string> uncheckeddata{};
bool ExceptDot(const std::string& str) 
{
    for (char ch : str) 
    {
        // Check if the character is a special character (excluding dot)
        if (!std::isalnum(ch) && ch != '.') 
        {
            return true;
        }
    }
    return false;
}


int all_row(std::vector <std::string> input,int strung_ordinates,std::pair<int,int> Ordinates)
{
  std::string upperrow=input[strung_ordinates-1].substr(Ordinates.first-1,Ordinates.second-Ordinates.first+3);
  std::string lowerrow=input[strung_ordinates+1].substr(Ordinates.first-1,Ordinates.second-Ordinates.first+3);
  char left=input[strung_ordinates][Ordinates.first-1];
  char right=input[strung_ordinates][Ordinates.second+1];
  std::string sides{};
  sides.push_back(left);
  sides.push_back(right);
  cout<<upperrow<<" upperrow"<<endl;
  cout<<lowerrow<<" lowerrow"<<endl;
  cout<<sides<<" sides"<<endl;
  if(ExceptDot(upperrow)||ExceptDot(lowerrow)||ExceptDot(sides))//ExceptDot(sides)
    return 1;
  else 
    return 0;
}





std::string IntVal(std::string strung,int &n,std::vector<std::string> input,int &strung_ordinates)
{
  std::pair<int,int> Ordinates{};
  int index, value{},toint{};

  std::string accumulator{};
  Ordinates.first=n;
  for(n;std::isdigit(static_cast<unsigned char>(strung[n]));n++)
  {
    accumulator.push_back(strung[n]);  
    index=n;
  }
  Ordinates.second=index;

  int row{},col{};
  cout<<Ordinates.first<<","<<Ordinates.second<<endl;

  if(all_row(input,strung_ordinates,Ordinates)==1)
    return accumulator;
  else
  {
   accumulator="0";
  return accumulator;
  }
}


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
 for(int j{0};j<input.size();j++)
  {
    //cout<<c<<"\n";
    std::string dynamicvalue{};
    for(int i{0};i<input[j].size();i++)
    {
      if(std::isdigit(static_cast<unsigned char>(input[j][i])))
      {
        //intvalue[k].push_back(c1);
        dynamicvalue=IntVal(input[j],i,input,j);  
        cout<<dynamicvalue<<endl;
        sum+=std::stoi(dynamicvalue);
      }
    }
  }
 cout<<"The effing sum is :"<<sum<<endl;

  // Close the file
  MyReadFile.close();
}
