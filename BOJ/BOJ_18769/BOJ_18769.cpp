#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct graph{
    int a,b,c;
    graph(int row, int col, int cost){
        a = row;
        b = col;
        c = cost;
    }
    bool operator<(graph &w){
        return c < w.c;
    }
};

int unf[250001];

int Find(int v){
    if(v==unf[v]) return unf[v];
    return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int T, R, C;
    cin>>T;
    while(T--){
        cin>>R>>C;
        vector<vector<int> > v(R, vector<int> (C,0));
        vector<graph> network;
        int cnt = 1, ans = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                v[i][j] = cnt++;
            }
        }

        for(int i = 1; i <= R*C; i++){
            unf[i] = i;
        }

        int rcost, ccost;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C-1; j++){
                cin>>rcost;
                // cout<<v[i][j]<<", "<<v[i][j+1]<<", "<<rcost<<"\n";
                network.push_back(graph(v[i][j], v[i][j+1], rcost));
                network.push_back(graph(v[i][j+1], v[i][j], rcost));
            }
        }

        for(int i = 0; i < R-1; i++){
            for(int j = 0; j < C; j++){
                cin>>ccost;
                // cout<<v[i][j]<<", "<<v[i+1][j]<<", "<<ccost<<"\n";
                network.push_back(graph(v[i][j], v[i+1][j], ccost));
                network.push_back(graph(v[i+1][j], v[i][j], ccost));
            }
        }

        sort(network.begin(), network.end());

        for(int i = 0; i < network.size(); i++){
            if(Find(network[i].a) != Find(network[i].b)){
                Union(network[i].a, network[i].b);
                ans += network[i].c;
            }
        }

        cout<<ans<<"\n";
    }


    return 0;
}