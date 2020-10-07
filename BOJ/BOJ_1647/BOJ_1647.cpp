#include<bits/stdc++.h>
using namespace std;

int unf[100005];

struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        val = c;
    }
    // bool operator<(const Edge &a){
    //     return this->val<a.val;
    // }
};

// bool asc(const Edge& a, const Edge& b){
//     return a.val < b.val;
// }
bool asc(Edge a, Edge b){
    return a.val < b.val;
}

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
    cin.tie(0);
    int n, m, a, b, c, cost = 0, cnt = 0;
    vector<Edge> ed;

    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        ed.push_back(Edge(a,b,c));
    }

    sort(ed.begin(), ed.end(), asc);
    
    for(int i = 0; i < m; i++){
        if(Find(ed[i].v1) != Find(ed[i].v2)){
            if(cnt == (n - 2)) break;
            cnt++;
            cost += ed[i].val;
            Union(ed[i].v1, ed[i].v2);
        }
    }

    cout<<cost<<"\n";

    return 0;
}