#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct city{
    int a,b,c;

    city(int aa, int bb, int cc){
        a = aa;
        b = bb;
        c = cc;
    }

    bool operator<(city &w){
        return c < w.c;
    }
};

int unf[100001];
int rnk[100001];

int Find(int v){
    if(unf[v] == v) return unf[v];
    return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    // if(a != b) unf[a] = b;
    if(rnk[a] > rnk[b]){
        unf[b] = a;
    }else{
        unf[a] = b;
        if(rnk[a] == rnk[b]){
            rnk[b] += 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m, a, b, cost, visit_cnt = 0;
    ll save = 0, total = 0;
    cin>>n>>m;
    vector<city> v;
    for(int i = 1; i <= n; i++){
        unf[i] = i;
        rnk[i] = 0;
    }
    for(int i = 0; i < m; i++){
        cin>>a>>b>>cost;
        v.push_back(city(a,b,cost));
        v.push_back(city(b,a,cost));
        total += cost;
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++){
        if(Find(v[i].a) != Find(v[i].b)){
            Union(v[i].a, v[i].b);
            save += v[i].c;
            visit_cnt++;
        }
    }

    if(n-1 == visit_cnt){
        cout<<total-save<<"\n";
    }else{
        cout<<-1<<"\n";
    }

    return 0;
}