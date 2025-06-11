#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, -1));
    vector<pair<int,int>> edge(m);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        G[a][b] = i;
        edge[i] = make_pair(a,b);
    }
    vector<int> dis(n,-1); dis[0] = 0;
    vector<pair<int,int>> memo(n);
    queue<int> que; que.push(0);
    while(!que.empty()){
        int i = que.front(); que.pop();
        for(int j = 0; j < n; j++) if(dis[j] == -1 && G[i][j] != -1){
            dis[j] = dis[i] + 1;
            memo[j] = make_pair(i,G[i][j]);
            que.push(j);
        }
    }
    if(dis[n-1] == -1){
        for(int i = 0; i < m; i++) cout << -1 << endl;
        return 0;
    }
    vector<int> shortest_path;
    int cur = n-1;
    while(cur != 0){
        shortest_path.push_back(memo[cur].second);
        cur = memo[cur].first;
    }
    vector<int> ans(m, dis[n-1]);
    for(int e : shortest_path){
        G[edge[e].first][edge[e].second] = -1;
        queue<int> que; que.push(0);
        vector<int> dis(n, -1); dis[0] = 0;
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(int j = 0; j < n; j++) if(dis[j] == -1 && G[i][j] != -1){
                dis[j] = dis[i] + 1;
                que.push(j);
            }
        }
        ans[e] = dis[n-1];
        G[edge[e].first][edge[e].second] = e;
    }
    for(int x:ans)cout << x << endl;
}