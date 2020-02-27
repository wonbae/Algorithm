#include<bits/stdc++.h>
using namespace std;

vector<int> adj[2001];    //이거 2차원 배열이다.
int visit[2001];
bool flag = false;

void dfs(int index){
    if(visit[index] == 5){
        cout<<1<<"\n";
        exit(0);
    }

    // visit[index] = true;
    for(int i = 0; i < adj[index].size(); i++){
        int next = adj[index][i];

        if(visit[next] != -1) continue;

        visit[next] = visit[index] + 1;
        dfs(next);
        visit[next] = -1;
    }
    // visit[index] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int a = 0, b = 0;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        memset(visit, -1, sizeof(visit));
        visit[i] = 1;
        dfs(i);
    }

    cout<<0<<"\n";

    return 0;
}