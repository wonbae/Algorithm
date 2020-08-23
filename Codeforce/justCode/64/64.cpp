#include<iostream>
using namespace std;

int a[21][21], ch[21], cnt = 0, n;

void dfs(int v){
    if(v+1 == n){
        cnt++;
        // for(int i = 0; i < n; i++){
        //     if(ch[i]){
        //         cout<<i+1<<" ";
        //     }
        // }cout<<"\n";
    }else{
        for(int i = 0; i < n; i++){    
            if(a[v][i] == 1 && ch[i] == 0){
                ch[i] = 1;
                dfs(i);
                ch[i] = 0;
            }
        }
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
    
    ch[0] = 1;
    dfs(0);

    cout<<cnt<<"\n";

    return 0;
}