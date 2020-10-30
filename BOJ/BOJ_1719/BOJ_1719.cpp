#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 2147000000

struct edge{
    int v;
    int cost;
    edge(int a, int b){
        v = a;
        cost = b;
    }
    bool operator<(const edge& w) const {
        return cost > w.cost;
    }
};

int dist[201];
int loc[201][201];

int main(){
    int n, m;
    vector<edge> ed[201];
    priority_queue<edge> pq;
    int a, b, c;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        ed[a].push_back(edge(b, c));
        ed[b].push_back(edge(a, c));
    }

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n ; k++) dist[k] = INF;
        pq.push(edge(i, 0));
        dist[i] = 0;

        while(!pq.empty()){
            int now = pq.top().v;
            int time = pq.top().cost;
            pq.pop();

            if(time > dist[now]) continue;

            for(int j = 0; j < ed[now].size(); j++){
                int next = ed[now][j].v;
                int ntime = time + ed[now][j].cost;

                if(dist[next] > ntime){
                    dist[next] = ntime;
                    pq.push(edge(next, ntime));
                    loc[next][i] = now;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) cout<<"- ";
            else cout<<loc[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}