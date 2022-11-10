#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int ch[21], dis[21];

int main(){
    freopen("input.txt","rt",stdin);
    int n, m;
    int a,b, mini = 2147000000;
    queue<int> q;
    vector<int> map[21];
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>a>>b;
        map[a].push_back(b);
    }

    q.push(1);
    ch[1] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i = 0; i < map[s].size(); i++){
            if(ch[map[s][i]] == 0){
                ch[map[s][i]] = 1;
                q.push(map[s][i]);
                dis[map[s][i]] = dis[s] + 1;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        cout<<i<<" : "<<dis[i]<<"\n";
    }


    return 0;
}