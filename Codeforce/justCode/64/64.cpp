#include<iostream>
using namespace std;

int a[21][21], visit[21][21], cnt, n;

void dfs(int L){
    if(L + 1 > n){

        return ;
    }else{
        dfs(L + 1);
    }
}

int main(){
    freopen("input.txt","rt",stdin);
    int m, r, c;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>r>>c;
        a[r - 1][c - 1] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }cout<<"\n";
    }

    dfs(0);

    return 0;
}