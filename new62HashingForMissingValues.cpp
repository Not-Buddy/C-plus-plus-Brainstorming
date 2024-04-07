#include <iostream>
#include <vector>
using namespace std;
int main()
{
  std::vector <int> vec{1,2,3,4,6,7,8,9,10,13,14};
  std::vector <int> vec2(15);
  for(int i{0};i<vec.size();i++)
  {
    vec2[vec[i]]++;
  }
  for(int i{0};i<vec2.size();i++)
  {
    if(vec2[i]==0)
    {
      cout<<"Missing element: "<<i<<endl;
    }
  }
  return 0;
}
