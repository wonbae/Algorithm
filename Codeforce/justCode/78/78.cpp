#include<iostream>
#include<algorithm>
using namespace std;

int unf[1001];

struct info{
    int a, b, c;
};

bool asc(info a, info b){
    return a.c < b.c;
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
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    info abc[1001];

    int v, e, a, b, c, cost = 0;
    cin>>v>>e;

    for(int i = 1; i <= e; i++){
        unf[i] = i;
    }

    for(int i = 0; i < e; i++){
        cin>>a>>b>>c;
        abc[i].a = a;
        abc[i].b = b;
        abc[i].c = c;
    }
    
    sort(abc, abc + e, asc);

    for(int i = 0; i < e; i++){
        // cout<<abc[i].a<<" "<<abc[i].b<<" "<<abc[i].c<<"\n";
        if(Find(abc[i].a) != Find(abc[i].b)){
            Union(abc[i].a, abc[i].b);
            cost += abc[i].c;
        }else{
            continue;
        }
    }

    cout<<cost<<"\n";

    return 0;
}