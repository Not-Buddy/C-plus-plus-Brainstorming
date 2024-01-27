#include <cstring>
#include <vector>
#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
using namespace std;

int Checker(std::string strung)
{
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
    if(t.find("red")!=std::string::npos)
      if(stoi(t.substr(t.find("red")-3,2))>12)
        Valid=0;
    if(t.find("blue")!=std::string::npos)
      if(stoi(t.substr(t.find("blue")-3,2))>14)
        Valid=0;
    if(t.find("green")!=std::string::npos)
      if(stoi(t.substr(t.find("green")-3,2))>13)
        Valid=0;
  }
    //cout<<Valid<<"\n";
  //cout<<strung.find("red")<<"\n";


  return Valid;
}


int main() {
    int Check,MAX_LINES{},sum=0;
    cout<<"Enter the amout of input that you will be providing: "<<endl;
    cin>>MAX_LINES;
    std::vector <std::string> lines{};
   

    cout << "Enter lines of text:" << std::endl;

    for (int i=0; i<MAX_LINES; i++) 
    {
      std::string str;
        cin>>str;
        getline(cin, str);
        lines.push_back(str);
    }
    for(size_t i{0};i<MAX_LINES;i++)
    {
      Check=Checker(lines[i]);
      if(Check==1)
      {
        std::string temp{};
        if(i<10)
        {

          temp=lines[i].substr(0,3);
          temp.erase(temp.size()-1);
          cout<<temp<<"\n";
          sum+=stoi(temp);
        }
        else 
        {
          temp=lines[i].substr(0,3);
          cout<<temp<<"\n";
          sum+=stoi(temp);
        }
      }
      else 
        continue;
    }
    cout<<"The sum is :"<<sum<<"\n";

    return 0;
}

