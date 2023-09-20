// 1854번 - K번째 최단경로 찾기, Dijkstra, priority queue 변형
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
typedef pair<int, int> pii;

// priority_queue<int> dist[1003];
// vector<pii> adj[1003];


int main(){
    fastio;

    int n, m, k;
    cin>>n>>m>>k;
    
    vector<vector<pii> > adj;
    adj.resize(n+1, vector<pii>());

    priority_queue<int> dist[n+1];

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }

    
    priority_queue<pii , vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    dist[1].push(0);

    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();


        for(auto nextNode : adj[curr]){
            int next = nextNode.first;
            int weight = nextNode.second;

            if(dist[next].size() < k || dist[next].top() > cost+weight){
                if(dist[next].size() == k){
                    dist[next].pop();    
                }

                dist[next].push(cost + weight);
                pq.push({(cost + weight), next});
            }
        }
    }


    for(int i = 1; i <= n; i++){
        if(dist[i].size() < k){
            cout<<-1<<"\n";
        }else{
            cout<<dist[i].top()<<"\n";
        }
    }


    return 0;
}