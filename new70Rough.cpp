#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::string input{};
    getline(cin,input);
    for(int ii{0};ii<input.size()-2;ii++)
    {
      for(char C:{'b','c','d'})
      {
        for(char V:{'a','e'})
        {
          std::string compare{};
          compare.push_back(C);
          compare.push_back(V);
          if(compare==input.substr(ii,2))
          {
            cout<<input.substr(ii,2)<<endl;
            input.insert(ii+2,1,'.');
          }
          //if(compare==input.substr(ii,2))
            //input.insert(ii,1,'.');
         }
      }
      cout<<input<<endl;
    }
}
