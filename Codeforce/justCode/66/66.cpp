#include<iostream>
#include<vector>
using namespace std;

int n, cnt = 0, ch[30];
vector<int> v[30];

void dfs(int ver){
    if(ver == n) cnt++;
    else{
        for(int i = 0; i < v[ver].size(); i++){
            if(ch[v[ver][i]] == 0){
                ch[v[ver][i]] = 1;
                dfs(v[ver][i]);
                ch[v[ver][i]] = 0;
            }
        }
    }
}

int main(){
    int m, a, b;
    freopen("input.txt","rt",stdin);
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        v[a].push_back(b);
    }

    ch[1] = 1;
    dfs(1);
    cout<<cnt<<"\n";
    return 0;
}