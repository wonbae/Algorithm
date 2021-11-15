#include<iostream>
#include<vector>
using namespace std;

vector<int> unf;

int find(int v){
    if(v == unf[v]){
        return v;
    }
    return unf[v] = find(unf[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        unf[a] = b;
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n,m;
    cin>>n>>m;

    unf.resize(n+1);
    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }
    vector<int> plan(m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int input;
            cin>>input;
            if(input){
                Union(i,j);
            }
        }
    }

    for(int i = 0; i < m; i++){
        cin>>plan[i];
    }

    int tmp=plan[0];
    tmp = find(tmp);

    for(int i = 1; i < m; i++){
        if(tmp != find(plan[i])){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}