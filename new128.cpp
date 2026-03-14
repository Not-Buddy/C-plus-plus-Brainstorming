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
  for(int ii{0};ii<testcases;ii++)
  {
	  int n;
	  cin>> n;
	  cin.ignore();

		int n , k , p;
	  long long m;
	  cin >> n >> k >> p >> m;
	  cin.ignore();
	  vector<long long> a(n);

	  for(int i{0};i<n;i++)
	  {
		  cin>>a[i];
	  }
  	
	  long long target_cost = a[p-1];

	  long long first_reach_cost = 0;

	  if(p>k)
	  {
		  vector<long long> prefix_cards;
			
		  for(int i{0};i<p-1;i++ )
		  {
			  prefix_cards.push_back(a[i]);
		  }

		  sort(prefix_cards.begin(), prefix_cards.end());

		  for(int i{0};i<p-k;i++)
		  {
			  first_reach_cost += prefix_cards[i];
		  }
	  }

	  long long first_play_cost = first_reach_cost + target_cost;

	  if(m< first_play_cost)
	  {
		  cout<<0<<"\n";
		  return;
	  }

	  long long plays = 1;
    m -= first_play_cost;

    long long cycle_reach_cost = 0;
    if (n > k) {
        vector<long long> other_cards;
        for (int i = 0; i < n; i++) {
            if (i != p - 1) {
                other_cards.push_back(a[i]);
            }
        }
        sort(other_cards.begin(), other_cards.end());
        for (int i = 0; i < n - k; i++) {
            cycle_reach_cost += other_cards[i];
        }
    }

    long long cycle_cost = cycle_reach_cost + target_cost;

    plays += m / cycle_cost;

    cout << plays << "\n";

	
  }

  return 0;
}
