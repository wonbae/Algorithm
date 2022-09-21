#include<bits/stdc++.h>
using namespace std;

vector<int> adj[54];
int N, node;


int dfs(int here){
    int leaf = 0;
    int child = 0;

    for(int there : adj[here]){
        if(there == node) continue;
        leaf += dfs(there);
        child++;
    }

    if(child == 0) return 1;
    return leaf;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin>>N;
    int a, root;

    for(int i = 0; i < N; i++){
        cin>>a;
        if(a == -1) root = i;
        else adj[a].push_back(i);
    }

    cin>>node;
    if(node == root){
        cout<<0<<"\n";
        return 0;
    }

    cout<<dfs(root)<<"\n";

    return 0;
}