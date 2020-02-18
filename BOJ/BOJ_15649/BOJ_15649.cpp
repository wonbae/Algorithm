#include <bits/stdc++.h>
using namespace std;

int n,m;
bool visit[9];  // 전역변순 true로 초기화 됨
vector<int> v;

void DFS(int cnt){
    if(cnt == m){
        for(int i = 0; i < v.size(); i++){
            cout<<v.at(i)<<" ";
        }
        cout<<"\n";
    }

    for(int i = 0; i < n; i++){
        if(!visit[i]){
            v.push_back(i + 1);
            visit[i] = true;
            DFS(cnt + 1);
            v.pop_back();
            visit[i] = false;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    DFS(0);

    return 0;
}