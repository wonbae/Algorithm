// Dijkstra
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define INF 2147000000

struct edge{
    int v,val;
    edge(int a, int b){
        v = a;
        val = b;
    }
    bool operator<(const edge& b)const{
        return val > b.val;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);

    int n, m, a, b, c;
    cin>>n>>m;

    vector<int> dist(n + 1, INF);
    vector<pair<int, int> > map[21];
    priority_queue<edge> pq;

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
    }

    pq.push(edge(1, 0));
    dist[1] = 0;
    while(!pq.empty()){
        int now = pq.top().v;
        int weight = pq.top().val;
        pq.pop();

        if(weight > dist[now]) continue; 

        for(int i = 0; i < map[now].size(); i++){
            int next = map[now][i].first;
            int nextwei = weight + map[now][i].second;

            if(dist[next] > nextwei){
                dist[next] = nextwei;
                pq.push(edge(next, nextwei));
            }
        }
    }

    for(int i = 2; i < dist.size(); i++){
        if(dist[i] == INF){
            cout<<i<<" : imposssible"<<"\n";
        }else{
            cout<<i<<" : "<<dist[i]<<"\n";
        }
    }
    return 0;
}