#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct CityRecord
{
  std::string Name;
  uint64_5 Population;
  double Latitude ,Longitude;
};

int main()
{
  std::vector<CityRecord> cities;
  cities.emplace_back("Melbourne",50000,2.4,9.4);
  cities.emplace_back("Lol-Town",50000,2.4,9.4);
  cities.emplace_back("Berlin",50000,2.4,9.4);
  cities.emplace_back("Paris",50000,2.4,9.4);
  cities.emplace_back("London",50000,2.4,9.4);
  
  for(const auto& city : cities)
  {
    if(city.Name=="Berline")
    {
      city.Population;
      break;
    }
  }
  std::map<std::string,CityRecord> cityMap;
  cityMap["Melbourne"]=CityRecord{"Melbourne",50000,2.4,9.4};
  cityMap["Lol-Town"]=CityRecord{"Lol-Town",50000,2.4,9.4};
  cityMap["Berlin"]=CityRecord{"Berline",50000,2.4,9.4};
  cityMap["Paris"]=CityRecord{"Paris",50000,2.4,9.4};
  cityMap["London"]=CityRecord{"London",50000,2.4,9.4};
  CityRecord& berlinData=cityMap["Berlin"];

  return 0;
}
