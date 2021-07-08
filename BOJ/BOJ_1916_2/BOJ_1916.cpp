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
    ios_base::sync_with_stdio(0),cin.tie(NULL);

    int n, m, sn, en, co, start_city, end_city;
    cin>>n>>m;

    vector<int> dist(n+1, INF);
    vector<pair<int, int> > v[1001];
    priority_queue<edge> pq;

    for(int i = 0; i < m; i++){
        cin>>sn>>en>>co;
        v[sn].push_back(make_pair(en,co));
    }

    cin>>start_city>>end_city;

    pq.push(edge(start_city,0));
    dist[start_city] = 0;

    while(!pq.empty()){
        int now = pq.top().v;
        int weight = pq.top().val;
        pq.pop();

        if(weight > dist[now]) continue;

        for(int i = 0; i < v[now].size(); i++){
            int next = v[now][i].first;
            int nextwei = weight + v[now][i].second;

            if(dist[next] > nextwei){
                dist[next] = nextwei;
                pq.push(edge(next, nextwei));
            }
        }
    }
    cout<<dist[end_city]<<"\n";
    return 0;
}