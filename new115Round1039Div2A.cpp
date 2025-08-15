#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <climits>
#include <algorithm>
#include <iterator>
typedef unsigned long long ll;
using namespace std;

int main()
{
	int t{};
	cin>>t;
	while(t--){
		long long n{},c{};
		cin>>n>>c;
		std::vector<long long> trashbags(n);
		for(int i{0};i<n;i++) cin>>trashbags[i];

		sort(trashbags.rbegin(),trashbags.rend());

		int saved=0;
		for(auto bag:trashbags)
		{
			if(bag*(1LL<<saved)<=c)
				++saved;
		}
		cout<<n-saved<<"\n";


	}

  return 0;
}
