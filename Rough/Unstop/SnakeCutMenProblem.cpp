#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int solve(int i,int j,int n,int m,vector<vector<char>>& matrix,int delrow[],int delcol[],vector<vector<long long int>>& dp,vector<vector<int>> &visited){
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    if(matrix[i][j]=='m') return 1;
    //if(dp[i][j]!=-1) return dp[i][j];
    long long int ans=0;
    for(int k=0;k<4;k++){
        int nr=i+delrow[k];
        int nc=j+delcol[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && (matrix[nr][nc]=='p' || matrix[nr][nc]=='m')){
            visited[nr][nc]=1;
            ans+=solve(nr,nc,n,m,matrix,delrow,delcol,dp,visited);
            visited[nr][nc]=0;
        }
    }
    return ans;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m;
    cin>>n>>m;
    vector<vector<char>>  matrix(n,vector<char>(m));
    vector<vector<int>> visited(n,vector<int>(m,0));
    int snake=0,man=0;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]=='s'){
                snake=1;
                x=i,y=j;
            }
            if(matrix[i][j]=='m') man=1;
        }
    }
    //cout<<x<<" "<<y;
    if(snake==0 || man==0) cout<<0;
    else{
        //cout<<x<<" "<<y;
        vector<vector<long long int>> dp(n,vector<long long int>(m,-1));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        visited[x][y]=1;
        cout<<solve(x,y,n,m,matrix,delrow,delcol,dp,visited);
    }
    return 0;
}