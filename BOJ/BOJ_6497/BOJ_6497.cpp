#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int unf[200001];

struct edge{
    int ss;
    int ee;
    int val;
    edge(int a, int b, int c){
        ss = a;
        ee = b;
        val = c;
    }
    bool operator<(const edge& w) const{
        return val < w.val;
    }
};

int find(int v){
    if(unf[v] == v) return v;
    return unf[v] = find(unf[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) unf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y, z;

    while(1){
        cin>>n>>m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i <= n; i++){
            unf[i] = i;
        }

        vector<edge> v;
        int sum = 0;

        for(int i = 0; i < m; i++){
            cin>>x>>y>>z;
            sum += z;
            v.push_back(edge(x, y, z));
        }

        sort(v.begin(), v.end());

        int cost = 0;
        for(int i = 0; i < v.size(); i++){
            if(find(v[i].ss) != find(v[i].ee)){
                cost += v[i].val;
                Union(v[i].ss, v[i].ee);
            }
        }

        cout<<sum - cost<<"\n";
    }

    return 0;
}