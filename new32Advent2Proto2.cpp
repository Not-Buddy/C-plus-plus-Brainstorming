#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  std::string strung{};
  getline(cin,strung);
  std::vector <std::string> tokens{};
  std::string token;
  std::istringstream ss(strung);
  char separator=';';
  while(std::getline(ss,token,separator))
  {
    tokens.push_back(token);
  }
  int Valid=1;
  for(std::string t:tokens)
  {
    cout<<t<<endl;
    if(t.find("red")!=std::string::npos)
      if(stoi(t.substr(t.find("red")-3,2))>12)
        Valid=0;
    if(t.find("blue")!=std::string::npos)
      if(stoi(t.substr(t.find("blue")-3,2))>12)
        Valid=0;
    if(t.find("green")!=std::string::npos)
      if(stoi(t.substr(t.find("green")-3,2))>12)
        Valid=0;
  }
    cout<<Valid<<"\n";
  //cout<<strung.find("red")<<"\n";


  return 0;
}
