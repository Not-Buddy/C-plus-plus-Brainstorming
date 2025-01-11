#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main()
{
  std::set<std::pair<int,int>> Loma{};
  Loma.insert(make_pair(1,2));
  Loma.insert(make_pair(1,3));
  for(auto P:Loma)
  {
    cout<<"First: "<<P.first<<" Second: "<<P.second<<endl;
  }
}
