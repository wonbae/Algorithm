// Prim MST : Priority_queue
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ch[30];

struct edge{
    int e;
    int val;
    edge(int a, int b){
        e = a;
        val = b;
    }
    bool operator<(const edge &b)const{
        return val > b.val;
    }
};

int main(){
    freopen("input.txt", "rt", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, ed, a, b, c, ans = 0;
    priority_queue<edge> q;
    vector<pair<int, int> > map[30];

    cin>>v>>ed;

    for(int i = 0 ; i < ed; i++){
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    q.push(edge(1, 0));
    while(!q.empty()){
        edge tmp = q.top();
        q.pop();

        int v = tmp.e;
        int cost = tmp.val;
        
        if(ch[v] == 0){
            ans += cost;
            ch[v] = 1;
            for(int i = 0; i < map[v].size(); i++){
                q.push(edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}

