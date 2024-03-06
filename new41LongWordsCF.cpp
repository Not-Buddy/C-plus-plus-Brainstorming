#include <iostream>
#include <string>
using namespace std;
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    std::string input{};
    std::string mid_nums{};

    int mid_num{};
    
    getline(cin,input);

    mid_num=input.size()-2;

    mid_nums=std::to_string(mid_num);

    if(input.size()>10)
    {
    cout<<input[0]<<mid_nums<<input[input.size()-1]<<endl;
    }
    else 
    {
      cout<<input<<endl;
    }
  }

  return 0;
}
