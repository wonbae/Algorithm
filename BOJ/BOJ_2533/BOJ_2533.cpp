#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

vector<int> adj[1000001];
int dp[1000001][2];
int visited[1000001];

void solve(int node){
    visited[node] = true;

    dp[node][0] = 1; // 0:early adopter

    for(auto &child : adj[node]){
        if(visited[child]) continue;

        solve(child);

        dp[node][1] += dp[child][0];
        dp[node][0] += min(dp[child][1], dp[child][0]);
    }

    return;
}

int main(){
    fastio;

    int n, u, v;
    cin>>n;

    for(int i = 1; i < n; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1);

    cout<<min(dp[1][0], dp[1][1])<<"\n";
}