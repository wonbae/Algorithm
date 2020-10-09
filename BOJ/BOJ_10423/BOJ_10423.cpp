#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int unf[1001];

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k, cost = 0;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }
    vector<int> generator;
    vector<pair<int, pair<int, int> > > edge;

    int g, u, v, w;
    for(int i = 0; i < k; i++){
        cin>>g;
        generator.push_back(g);
    }

    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        edge.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < k - 1; i++){
        Union(generator[i], generator[i + 1]);
    }
    
    for(int i = 0; i < m; i++){
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        if(Find(a) != Find(b)){
            Union(a, b);
            cost += edge[i].first;
        }
    }

    cout<<cost<<"\n";
    return 0;
}