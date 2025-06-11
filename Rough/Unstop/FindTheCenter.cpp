#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int> >& edges) {
    map<int, int> m;
    for(auto edge : edges){
        m[edge[0]]++;
        m[edge[1]]++;
    }
    int ans = -1, maxVal = 0;
    for(auto it : m){
        if(it.second > maxVal){
            ans = it.first;
            maxVal = it.second;
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<vector<int> > v(n);
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        v[i].push_back(x);
        v[i].push_back(y);
    }
    cout<<findCenter(v)<<endl;
    return 0;
}