#include<iostream>
#include<vector>
using namespace std;

int N, P, ch[103], cnt = 0;
vector<int> v[102];

void dfs(int idx){
    if(ch[idx] == true){
        return ;
    }
    ch[idx] = true;
    cnt++;
    for(int i = 0; i < v[idx].size(); i++){
        dfs(v[idx][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>N>>P;

    for(int i = 0; i < P; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout<<cnt-1<<"\n";

    return 0;
}