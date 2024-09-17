#include <climits>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
//typedef long long ll;
using namespace std;

long long sum(long long l,long long r,long long k)
{
	return (r*(r+1)/2)-((l*(l-1))/2)+((r-l+1)*k);
}

long long solve()
{
	  long long n,k;
	  cin>>n>>k;
	  auto getSum = [&] (long long l, long long r) -> long long {
	  return (r*(r+1)/2)-(l*(l-1)/2);
	  };
	  long long left=k,right=k+n-1,answer=LLONG_MAX;
	  while(left<=right)
	  {
		  long long mid=(left+right)/2;
		 long long sum1 = getSum(k,mid),sum2=getSum(mid+1,k+n-1);
		  answer=min(answer,abs(sum1-sum2));
		  if(sum1>sum2) right=mid-1;
		  else left=mid+1;
	  }
	  return answer;
}
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	  long long ans = solve();
	  cout<<ans<<endl;
  }

  return 0;
}
