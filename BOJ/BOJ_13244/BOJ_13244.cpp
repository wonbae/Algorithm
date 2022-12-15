#include<bits/stdc++.h>
using namespace std;

int visited[1001];
vector<int> v[1001];

void dfs(int here){
    visited[here] = 1;
    for(int i = 0; i < v[here].size(); i++){
        if(!visited[v[here][i]]){
            dfs(v[here][i]);
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t, m, n;
    cin>>t;

    while(t--){
        cin>>n>>m;
        int cnt = 0;

        for(int i = 0; i < n; i++) v[i].clear();
        fill(visited, visited+1001, 0);

        for(int i = 0; i < m; i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }

        if(m == n-1 && cnt == 1) cout<<"tree\n";
        else cout<<"graph\n";
    }

    return 0;
}