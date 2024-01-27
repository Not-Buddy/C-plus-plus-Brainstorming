#include <cstring>
#include <vector>
#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm>
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
  int Product{},Max_red{1},Max_blue{1},Max_green{1};
  for(std::string t:tokens)
  {
    if(t.find("red")!=std::string::npos)
       Max_red=std::max(Max_red,stoi(t.substr(t.find("red")-3,2)));                                     //if(stoi(t.substr(t.find("red")-3,2))>12)

    if(t.find("blue")!=std::string::npos)
       Max_blue=std::max(Max_blue,stoi(t.substr(t.find("blue")-3,2)));                                     //if(stoi(t.substr(t.find("red")-3,2))>12)
                                                                                                       //if(stoi(t.substr(t.find("blue")-3,2))>14)
    if(t.find("green")!=std::string::npos)
       Max_green=std::max(Max_green,stoi(t.substr(t.find("green")-3,2)));                                    //    if(stoi(t.substr(t.find("green")-3,2))>13)
  }
  
  Product=Max_blue*Max_green*Max_red;
  cout<<Product<<endl;
    //cout<<Valid<<"\n";
  //cout<<strung.find("red")<<"\n";


  return Product;
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
      sum+=Check;
    }
    cout<<"The of all the things is :"<<sum<<endl;

    return 0;
}

