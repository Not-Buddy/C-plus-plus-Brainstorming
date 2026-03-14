#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
	  int n;
	  cin>> n;
	  cin.ignore();
		
	  std::vector<int> frequency(n*n+1, 0);

	  int max_freq = 0;

	  for(int i{0};i<n*n;i++)
	  {
		  int c;
		  cin>>c;
		  frequency[c]++;
		
		  if(frequency[c]> max_freq)
		  {
			  max_freq = frequency[c];
		  }
	  }

	  if(max_freq<= n*n-n)
	  {
	  	cout<<"YES\n";
	  }
	  else 
	  {
		  cout<<"NO\n";
	  }


	
  }

  return 0;
}
