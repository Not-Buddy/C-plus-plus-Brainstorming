#include <iostream>
#include <vector>
using namespace std;
int BinSearch(std::vector <int> const vec,int key)
{
  int l{},h{},mid{};
  h=vec.size()-1;
  while(l<=h)
  {
    mid=(l+h)/2;
    if(key==vec[mid])
      return mid;
    else if(key<vec[mid])
      h=mid-1;
    else 
      l=mid+1;
  }
  return -1;
}
  
int main() 
{
  std::vector <int> xd{1,2,3,4,5,6,7,8,9,10};
  cout<<BinSearch(xd,4)<<endl;


  return 0;

