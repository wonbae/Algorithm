#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[10001];
int visited[10001], dp[10001],a,b,mx;


int dfs(int here){
    visited[here] = 1;
    int ret = 1;

    for(int there : adj[here]){
        if(visited[there]) continue;
        ret += dfs(there);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>N>>M;

    for(int i = 0; i < M; i++){
        cin>>a>>b;
        adj[b].push_back(a);
    }

    
    for(int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }    

    for(int i = 1; i <= N; i++){
        if(mx == dp[i]) cout<<i<<" ";
    }
    return 0;
}