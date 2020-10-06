#include <iostream>
using namespace std;

int unf[1001];

int find(int v){
    if(v == unf[v]) return v;
    return unf[v] = find(unf[v]);
}

void UNION(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) unf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    int n, m, a, b;
    
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        UNION(a, b);
    }

    cin>>a>>b;
    a = find(a);
    b = find(b);
    if(a == b) cout<<"YES";
    else cout<<"NO";
    return 0;
}