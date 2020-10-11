#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 2147000000000000000
typedef long long ll;

struct edge{
    int v;
    ll w;
    int k;
    edge(int a, ll b, int c){
        v = a;
        w = b;
        k = c;
    }
    bool operator<(const edge& b)const{
        return w > b.w;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, a, b, c;
    cin>>n>>m>>k;

    // vector<vector<ll> > dist(n + 1, vector<ll>(21, INF));
    ll dist[10005][25];
    vector<pair<int, int> > map[10005];
    priority_queue<edge> pq;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dist[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    pq.push(edge(1, 0, k));
    dist[1][k] = 0;

    while(!pq.empty()){
        int now = pq.top().v;
        ll time = pq.top().w;
        int pack = pq.top().k;
        pq.pop();

        if(time != dist[now][pack]) continue;

        for(int i = 0; i < map[now].size(); i++){
            int next = map[now][i].first;
            ll ntime = time + map[now][i].second;
            int npack = pack - 1;

            if(dist[next][pack] > ntime){
                dist[next][pack] = ntime;
                pq.push(edge(next, ntime, pack));
            }

            if(pack > 0){
                if(dist[next][npack] > time){
                    dist[next][npack] = time;
                    pq.push(edge(next, time, npack));
                }
            }
        }
    }

    ll mini = INF;
    for(int i = 0; i < k; i++){
        if(mini > dist[n][i]) mini = dist[n][i];
    }

    cout<<mini<<"\n";
    return 0;
}