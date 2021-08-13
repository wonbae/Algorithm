#include<iostream>
using namespace std;

int inf[1000001];
int rnk[1000001];

int Find(int v){
    if(v == inf[v]) return inf[v];
    return inf[v] = Find(inf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    // if(a != b) inf[a] = b;
    if(rnk[a] > rnk[b]){
        inf[b] = a;
    }else{
        inf[a] = b;
        if(rnk[a] == rnk[b]){
            rnk[b] += 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    for(int i = 0; i <= n; i++){
        inf[i]=i;
        rnk[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int cal, a, b;
        cin>>cal>>a>>b;
        if(cal){
            if(Find(a) != Find(b)){
                cout<<"NO"<<"\n";
            }else{
                cout<<"YES"<<"\n";
            }
        }else{
            Union(a,b);
        }
    }
    return 0;
}