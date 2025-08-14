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
  int testcases{};
  cin>>testcases;
  for(int l{0};l<testcases;l++)
  {
	int n{};
	cin>>n;
	std::vector<int> arr(n),mn(n),mx(n);
	for(int i{0};i<n;i++) cin>>arr[i];
	mn[0]=arr[0];
	for(int i{1};i<n;i++)
		mn[i]=min(mn[i-1],arr[i]);
	mx[n-1]=arr[n-1];
	for(int i{n-2};i>=0;i--)
		mx[i]=max(mx[i+1],arr[i]);

	for(int i{0};i<n;i++)
		cout<<(arr[i]==mn[i]||arr[i]==mx[i])?'1':'0';
	cout<<endl;
  }

  return 0;
}
