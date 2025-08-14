#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

//unsolved
int main()
{
  int testcases{};
  cin>>testcases;
  for(int j{0};j<testcases;j++)
  {
	int n{},k{};
	cin>>n>>k;
	vector<int> S(n),T(n);
	for(int i{0};i<n;i++)cin>>S[i];
	for(int i{0};i<n;i++)cin>>T[i];

	unordered_map<int, vector<int>> S_groups, T_groups;

	for(int x:S){
		int remainder=x%k;
		S_groups[remainder].push_back(x);
	}

	for(int x:T){
		int remainder=x%k;
		T_groups[remainder].push_back(x);
	}
	
	bool possible = true;
	for(auto& [remainder,s_vals]: S_groups){
		if(T_groups.find(remainder)==T_groups.end()||
			s_vals.size()!=T_groups[remainder].size())
		{

			possible=false;
			break;
		}
		sort(s_vals.begin(),s_vals.end());
		sort(T_groups[remainder].begin(), T_groups[remainder].end());
		for(int i{0};i<s_vals.size();i++)
		{
			int s_canonical = min(s_vals[i]%k,k-(s_vals[i]%k));
			int t_canonical = min(T_groups[remainder][i],k-(T_groups[remainder][i]%k));
			if (s_canonical > t_canonical) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) break;
        }
        // Check for groups that exist in T but not in S
        for (auto& [remainder, t_vals] : T_groups) {
            if (S_groups.find(remainder) == S_groups.end()) {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
	}

  return 0;
}
