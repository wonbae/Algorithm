#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 2147000000;

struct edge{
    int s;
    int val;
    edge(int a, int b){
        s = a;
        val = b;
    }
    bool operator<(const edge& b) const{
        return val > b.val;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, c, st, end;
    cin>>n>>m;
    vector<pair<int, int> > map[1001];
    priority_queue<edge> pq;
    vector<int> dist(n + 1, 1e9);

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
    }

    cin>>st>>end;

    pq.push(edge(st, 0));
    dist[st] = 0;

    while(!pq.empty()){
        int now = pq.top().s;
        int cost = pq.top().val;
        pq.pop();

        if(cost != dist[now]) continue;

        for(int i = 0; i < map[now].size(); i++){
            int next = map[now][i].first;
            int ncost = cost + map[now][i].second;

            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.push(edge(next, ncost));
            }
        }
    }

    cout<<dist[end]<<"\n";

    return 0;
}