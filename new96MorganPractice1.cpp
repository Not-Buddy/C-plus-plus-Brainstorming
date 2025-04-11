#include <iostream>
using namespace std;
int maxletters(std::string const s)
{


}
int main()
{
	int n{};
	cin>>n;
	std::vector<std::string> Strungs{};
	for(int i{0};i<n;i++)
	{
		std::string Temp{};
		getline(cin,Temp);
		Strungs.push_back(Temp);
	}

	for(int i{0};i<n;i++)
	{
		string s=Strungs[i];
		sort(s.begin(),s.end());
		int most_max_letters=maxletters(s);
	}
	

	return 0;
}
