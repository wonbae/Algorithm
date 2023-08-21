#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<int> tmp;
vector<bool> ch;

void dfs(int cnt){
    if(cnt == m){
        for(int i = 0; i < cnt; i++){
            cout<<tmp[i]<<" ";
        }cout<<"\n";
        return;
    }

    int last = 0;

    for(int i = 0; i < n; i++){
        if(!ch[i] && v[i] != last){
            last = v[i];
            tmp[cnt] = v[i];
            ch[i] = true;
            dfs(cnt + 1);
            ch[i] = false;
        }
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin>>n>>m;

    v.resize(n);
    tmp.resize(n);
    ch.resize(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    dfs(0);
    
    return 0;
}

