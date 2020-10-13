#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 2147483640

long long dist[1005];
int route[1005];
vector<pair<int, long long> > map[1005];
vector<int> ans;

struct edge{
    int v;
    long long val;
    edge(int a, long long b){
        v = a;
        val = b;
    }
    bool operator<(const edge& w) const{
        return val > w.val;     //최소힙
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, a, b, c, st = 0, end = 0;
    cin>>n>>m;
    
    priority_queue<edge> pq;

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
    }
    for(int i = 1; i <= n; i++) dist[i] = INF;
    cin>>st>>end;
    
    dist[st] = 0;
    pq.push(edge(st, 0));
    
    while(!pq.empty()){
        int now = pq.top().v;
        long long cost = pq.top().val;
        pq.pop();

        if(cost > dist[now]) continue;
        
        for(int i = 0; i < map[now].size(); i++){
            int next = map[now][i].first;
            long long sum = cost + map[now][i].second;

            if(dist[next] > sum){
                dist[next] = sum;
                route[next] = now;
                pq.push(edge(next, dist[next]));
            }
        }
    }
    
    cout<<dist[end]<<"\n";

    int tmp = end;
    while(tmp){
        ans.push_back(tmp);
        tmp = route[tmp];
    }

    cout<<ans.size()<<"\n";

    for(int i = ans.size() - 1; i >= 0; i--){
        cout<<ans[i]<<" ";
    }cout<<"\n";

    return 0;
}