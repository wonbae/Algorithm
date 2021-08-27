#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 2147000000

struct road{
    int dt;
    int sc;
    road(int b, int c){
        dt = b;
        sc = c;
    }
    bool operator<(const road& t) const{
        return sc < t.sc;
    }
};

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, d;
    cin>>n>>d;

    vector<int> dist(10001, INF);
    vector<pair<int, int> > map[10001];
    priority_queue<road> pq;

    int depart, desti, shortcut;
    for(int i = 0; i < n; i++){
        cin>>depart>>desti>>shortcut;
        map[depart].push_back(make_pair(desti, shortcut));
    }
    
    int end = 0;
    pq.push(road(0, 0));
    dist[0] = 0;
    while(!pq.empty()){
        int now = pq.top().dt;
        int w = pq.top().sc;
        pq.pop();

        if(w > dist[now]) continue;

        for(int i = 0; i < map[now].size(); i++){
            int next = map[now][i].first;
            int nw = map[now][i].second + w;
            if(dist[next] > nw){
                dist[next] = nw;
                end = next;
                pq.push(road(next, nw));
            }
        }

        if(now+1 <= d && dist[now+1] > w+1){
            dist[now+1] = w+1;
            pq.push(road(now+1, w+1));
        }
    }
    cout<<dist[d]<<"\n";
    return 0;
}