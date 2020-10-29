#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
#define ll double
#define pii pair<int, int> 

struct info{
    int r;
    int c;
    ll cost;
    info(int a, int b, ll d){
        r = a;
        c = b;
        cost = d;
    }
    bool operator<(const info& w) const { 
        return cost < w.cost;
    }
};

vector<info> v;
int unf[1001];

ll dist(pair<int, int> a, pair<int, int> b){
    ll tmper = pow((a.first - b.first),2) + pow((a.second - b.second), 2);
    return sqrt(tmper);
}

int find(int v){
    if(unf[v] == v) return v;
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

    int n,m;
    cin>>n>>m;
    int x, y;
    vector<pair<int, int> > cordi;

    for(int i = 1; i <= n ; i++){
        unf[i] = i;
    }

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        cordi.push_back(make_pair(x,y));
    }

    ll distance;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            distance = dist(cordi[i], cordi[j]);
            v.push_back(info(i + 1, j + 1, distance));
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++){
        cin>>x>>y;
        if(find(x) != find(y)){
            Union(x, y);
        }
    }

    ll ans = 0;

    for(int i = 0; i < v.size(); i++){
        if(find(v[i].r) != find(v[i].c)){
            ans += v[i].cost;
            Union(v[i].r, v[i].c);
        }
    }
    cout<<fixed;
    cout<<setprecision(2);
    cout<<ans<<"\n";


    return 0;
}