#include<iostream>
#include<vector>
using namespace std;

int n, w, sum = 0, mini = 2147000000, ch[20];
vector<pair<int, int> > v[20];

void dfs(int ver, int sum){
    if(ver == n){
        if(mini > sum){
            mini = sum;
        }
    }else{
        for(int i = 0; i < v[ver].size(); i++){
            if(ch[v[ver][i].first] == 0){
                ch[v[ver][i].first] = 1;
                dfs(v[ver][i].first, sum + v[ver][i].second);
                ch[v[ver][i].first] = 0;
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
        v[a].push_back(make_pair(b, w));
    }

    ch[1] = 1;
    dfs(1, 0);

    cout<<mini<<"\n";

    return 0;
}