#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int unf[1001];
int N,M;

struct edge{
    int s,e,w;
    edge(int a, int b, int c){
        s = a;
        e = b;
        w = c;
    }
    bool operator<(edge &ed){
        return w < ed.w;
    }
};

int Find(int v){
    if(unf[v] == v) return unf[v];
    return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a] = b;
}

bool cmp(edge a, edge b){
    return a.w > b.w;
}

void init(){
    for(int i = 1; i <= N; i++){
        unf[i] = i;
    }
    unf[0] = 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int a, b, c;
    cin>>N>>M;
    vector<edge> v;

    cin>>a>>b>>c;
    v.push_back(edge(a,b,c));

    for(int i = 0; i < M; i++){
        cin>>a>>b>>c;
        v.push_back(edge(a,b,c));
    }

    sort(v.begin(), v.end());

    init();

    int ohru = 0, naeri = 0;

    for(int i = 0; i < v.size(); i++){
        if(Find(v[i].s) != Find(v[i].e)){
            Union(v[i].s, v[i].e);
            if(v[i].w == 0){
                ohru++;
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    init();

    for(int i = 0; i < v.size(); i++){
        if(Find(v[i].s) != Find(v[i].e)){
            Union(v[i].s, v[i].e);
            if(v[i].w == 0){
                naeri++;
            }
        }
    }

    cout<<(ohru*ohru)-(naeri*naeri)<<"\n";

    return 0;
}