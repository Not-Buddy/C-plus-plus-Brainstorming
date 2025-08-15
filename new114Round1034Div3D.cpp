#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <climits>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main()
{
	int t{};
	cin>>t;
	while(t--){

		long long n{};
		cin>>n;
		std::vector<int> vals(n);
		for(int i{0};i<n;i++) cin>>vals[i];

		long long sum=( n * (n+1) * (n+2) )/6;
		for(int i{0};i<n-1;i++)
		{
			if(vals[i]<vals[i+1])
			{
				sum-=(i+1)*(n-i-1);
			}
		}
		cout<<sum<<"\n";
	}

  return 0;
}
