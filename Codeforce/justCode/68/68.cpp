#include<iostream>
#include<vector>
using namespace std;

int n, w, sum = 0, mini = 2147000000, ch[20], weight[20];
vector<int> v[20];

void dfs(int ver){
    if(ver == n){
        if(mini > sum){
            mini = sum;
            sum = 0;
        }
    }else{
        for(int i = 1; i <= v[ver].size(); i++){
            if(ch[v[ver][i]] == 0){
                ch[v[ver][i]] = 1;
                sum += weight[v[ver][i]];
                dfs(v[ver][i]);
                ch[v[ver][i]] = 0;
                // sum -= weight[v[ver][i]];
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
        v[a].push_back(b);
        weight[v[a][b]] = w;
    }

    ch[1] = 1;
    dfs(1);

    cout<<mini<<"\n";

    return 0;
}