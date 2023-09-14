#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

vector<int> adj[1000001];
int visited[1000001];
int dp[1000001][2]; // 0:early, 1:normal

void solve(int node){

    dp[node][0] = 1;

    visited[node] = true;

    for(auto &child : adj[node]){
        if(visited[child]) continue;
        solve(child);

        dp[node][1] += dp[child][0];
        dp[node][0] += min(dp[child][0], dp[child][1]);
    }

    return;
}

int main(){
    fastio;
    
    int n;
    cin>>n;

    int u, v;
    for(int i = 0; i < n-1; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1);

    cout<<min(dp[1][0], dp[1][1])<<"\n";

    return 0;
}
