#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct edge{
    int e;
    int val;
    edge(int a, int b){
        e = a;
        val = b;
    }
    bool operator<(const edge& w) const {
        return val > w.val;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m, st, a, b, c;
    cin>>n>>m>>st;

    vector<pair<int, int> > map[20001];
    priority_queue<edge> pq;
    vector<int> dist(n + 1, 1e9);

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
    }

    pq.push(edge(st, 0));
    dist[st] = 0;
    while(!pq.empty()){
        int now = pq.top().e;
        int cost = pq.top().val;
        pq.pop();

        if(cost > dist[now]) continue;

        for(int i = 0; i < map[now].size(); i++){
            int next = map[now][i].first;
            int ncost = cost + map[now][i].second;

            if(dist[next] > ncost){
                dist[next] = ncost;
                pq.push(edge(next, ncost));
            }
        }
    }

    for(int i = 1; i < dist.size(); i++){
        if(dist[i] == 1e9) cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }

    return 0;
}