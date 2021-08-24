#include<iostream>
using namespace std;

int unf[1001];

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
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int N, M;
    cin>>N>>M;

    for(int i = 1; i <= N; i++){
        unf[i] = i;
    }

    for(int i = 0; i < M; i++){
        int u,v;
        cin>>u>>v;
        if(Find(u) != Find(v)){
            Union(u,v);
        }
    }
    
    bool check[1001]={false,};
    int cnt = 0;

    for(int i = 1; i <= N; i++){
        int tmp = Find(i);
        if(!check[tmp]){
            cnt++;
            check[tmp] = true;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}