#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, m, a, b;
    cin>>n>>m;
    // vector<vector<int> > graph(n+1, vector<int> (n+1, 0));
    vector<vector<int> > graph(n+1, vector<int> ());
    vector<int> degree(n+1, 0);
    queue<int> Q;

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        // graph[a][b] = 1;
        graph[a].push_back(b);
        degree[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) Q.push(i);
    }

    while(!Q.empty()){
        int now = Q.front();
        Q.pop();

        cout<<now<<" ";

        for(int i = 0; i < graph[now].size(); i++){
            degree[graph[now][i]]--;
            if(degree[graph[now][i]] == 0) Q.push(graph[now][i]);
        }
    }
    return 0;
}