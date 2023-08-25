#include<bits/stdc++.h>
using namespace std;

int n, m, v;
vector<vector<int>> mp;
vector<bool> check;

void DFS(int st){
    check[st] = true;
    cout<<st<<" ";

    for(int i = 1; i <= n; i++){
        if(mp[st][i] == 1 && check[i] == false){
            DFS(i);
        }
    }

    return ;
}


void BFS(int st){
    queue<int> q;
    q.push(st);
    check[st] = true;
    cout<<st<<" ";

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int next = 1; next <= n; next++){
            if(mp[now][next] == 1 && check[next] == false){
                q.push(next);
                cout<<next<<" ";
                check[next] = true;
            }
        }
    }

    return ;
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin>>n>>m>>v;

    mp.resize(n+1, vector<int>(n+1, 0));
    check.resize(n+1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;

        mp[a][b] = 1;
        mp[b][a] = 1;
    }

    DFS(v);

    cout<<"\n";

    check.assign(n+1, false);
    
    BFS(v);

    return 0;
}