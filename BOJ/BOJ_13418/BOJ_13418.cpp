#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int unf[1001];

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

int main(){
    int N,M;
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

    for(int i = 0; i < N; i++){
        unf[i] = i;
    }

    for(int i = 0; i < v.size(); i++){
        
    }


    return 0;
}