#include<iostream>
using namespace std;

int n, w, sum = 0, mini = 2147000000, ch[20];
int v[30][30];

void dfs(int ver, int sum){
    if(ver == n){
        if(mini > sum){
            mini = sum;
        }
    }else{
        for(int i = 1; i <= n; i++){
            if(v[ver][i] > 0 && ch[i] == 0){
                ch[i] = 1;
                dfs(i, sum + v[ver][i]);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    int m, a,b;

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b>>w;
        v[a][b] = w;
    }

    ch[1] = 1;
    dfs(1, 0);

    cout<<mini<<"\n";

    return 0;
}