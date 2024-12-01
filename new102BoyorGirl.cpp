#include <iostream>
#include <string>
#include <set>
int main()
{
    std::string Input{};
    std::set<char> Ans{};
    std::getline(std::cin,Input);
    for(int i{0};i<Input.size();i++)
    {
      //std::cout<<Input[i]<<std::endl;
      Ans.insert(Input[i]);
    }
    if(Ans.size()%2==0)
    {
      std::cout<<"CHAT WITH HER!"<<std::endl;
    }
    else 
    {
      std::cout<<"IGNORE HIM!"<<std::endl;
    }
  return 0;
}
