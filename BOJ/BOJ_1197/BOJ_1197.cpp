#include<bits/stdc++.h>
using namespace std;

int unf[10001];

struct edge{
    int sv;
    int ev;
    int val;
    edge(int a, int b, int c){
        sv = a;
        ev = b;
        val = c;
    }
    bool operator<(const edge &w) const {
        return val < w.val;
    }
};

int find(int v){
    if(v == unf[v]) return v;
    return unf[v] = find(unf[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) unf[a] = b;
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, a, b, c;
    long long cost = 0;
    cin>>v>>e;
    vector<edge> map;

    for(int i = 1; i <= v; i++){
        unf[i] = i;
    }
    for(int i = 0; i < e; i++){
        cin>>a>>b>>c;
        map.push_back(edge(a, b, c));
    }
    sort(map.begin(), map.end());

    for(int i = 0; i < e; i++){
        if(find(map[i].sv) != find(map[i].ev)){
            cost += map[i].val;
            Union(map[i].sv, map[i].ev);
        }
    }

    cout<<cost<<"\n";
    return 0;
}