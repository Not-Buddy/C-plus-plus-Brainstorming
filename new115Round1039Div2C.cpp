#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <climits>
#include <algorithm>
typedef int ll;
using namespace std;

int main()
{
	int t{};
	cin>>t;
	while(t--){
		ll n{};
		cin>>n;
		std::vector<ll> arr(n);
		for(int i{0};i<n;i++) cin>>arr[i];

		int maxi=arr[0]-1+arr[0];
		int f=0;
		for(int i{1};i<n;i++)
		{
			if(arr[i]<=maxi)
				maxi=min(maxi,arr[i]-1+arr[i]);
			else 
			{
				f=1;
				break;
			}
		}

		if(f==1) cout<<"No\n";
		else cout<<"Yes\n";
	
	}

  return 0;
}
