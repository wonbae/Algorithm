#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 2147000000

struct edge{
    int v;
    int time;
    edge(int a, int b){
        v = a;
        time = b;
    }
    bool operator<(const edge& b)const{
        return time > b.time;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, a, b, c;
    cin>>n>>m>>x;

    vector<int> dist(n + 1, INF);
    vector<pair<int, int> > map[1001];
    priority_queue<edge> pq;
    vector<int> ans[1001];

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
    }

    for(int k = 1; k <= n; k++){
        pq.push(edge(k, 0));
        dist[k] = 0;

        while(!pq.empty()){
            int now = pq.top().v;
            int time = pq.top().time;
            pq.pop();

            if(time > dist[now]) continue;

            for(int i = 0; i < map[now].size(); i++){
                int next = map[now][i].first;
                int cost = time + map[now][i].second;
                if(dist[next] > cost){
                    dist[next] = cost;
                    pq.push(edge(next, cost));
                }
            }
        }
        for(int i = 1; i < dist.size(); i++){
            ans[k].push_back(dist[i]);
            dist[i] = INF;
        }
    }

    int maxi = -INF;
    for(int i = 1; i <= n; i++){
        int tmp = ans[i][x - 1] + ans[x][i-1];
        if(maxi < tmp) maxi = tmp;
    }
    cout<<maxi<<"\n";
    
    return 0;
}