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
		std::vector<long long> arr(n);
		for(int i{0};i<n;i++) cin>>arr[i];

		int last=-1;
		int l=0,r=n-1;
		while(l<r)
		{
			int sign=(arr[l]-arr[r])/abs(arr[l]-arr[r]);
				if(sign==last)
					cout<<"RL";
				else
					cout<<"LR";
			last=-last;
			l++;
			r--;
		}
		if(n%2==1)
			cout<<"L"<<"\n";
		else 
			cout<<"\n";
	}

  return 0;
}
