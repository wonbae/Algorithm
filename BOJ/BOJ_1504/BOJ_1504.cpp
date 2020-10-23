#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2147000000
#define ll long long

struct edge{
    int v;
    ll c;
    edge(int a, ll b){
        v = a;
        c = b;
    }
    bool operator<(const edge& w) const{
        return c > w.c;
    }
};

int N, E;
vector<pair<int, int> > v[801];
int dist[801][801];
priority_queue<edge> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>E;
    int a, b, c;
    int v1, v2;

    for(int i = 0; i < E; i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cin>>v1>>v2;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dist[i][j] = INF;
        }
    }

    for(int i = 1; i <= N; i++){
        pq.push(edge(i, 0));
        dist[i][i] = 0;

        while(!pq.empty()){
            int now = pq.top().v;
            ll cost = pq.top().c;
            pq.pop();

            if(cost > dist[i][now]) continue;

            for(int k = 0; k < v[now].size(); k++){
                int next = v[now][k].first;
                ll ncost = cost + v[now][k].second;

                if(dist[i][next] > ncost){
                    dist[i][next] = ncost;
                    pq.push(edge(next, ncost));
                }
            }
        }
    }

    ll ans = 0;
    
    if(dist[1][v1] == INF || dist[v1][v2] == INF || dist[v2][N] == INF){
        cout<<-1<<"\n";
        return 0;
    }else{
        ans += min(dist[1][v1] + dist[v1][v2] + dist[v2][N], dist[1][v2] + dist[v2][v1] + dist[v1][N]);
        cout<<ans<<"\n";
    }
    return 0;
}