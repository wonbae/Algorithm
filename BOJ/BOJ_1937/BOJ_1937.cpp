#include<iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int n;
int forest[501][501], dp[501][501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];

    dp[x][y] = 1;
    for(int idx = 0; idx < 4; idx++){
        int nx = x + dx[idx];
        int ny = y + dy[idx];

        if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
        if(forest[nx][ny] <= forest[x][y]) continue;
        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int ans = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>forest[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, dfs(i,j));
        }
    }
    cout<<ans<<"\n";
    return 0;
}