#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n, m, ans = -1;
    int t1, t2;
    vector<int> v[101];
    int dist[101] = {0,};
    queue<int> q;

    cin>>n>>t1>>t2>>m;

    for(int i = 0; i < m; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    q.push(t1);
    while(!q.empty()){
        int st = q.front();
        q.pop();

        if(st == t2){
            ans = dist[st];
            break;
        } 

        for(int i = 0; i < v[st].size(); i++){
            int check = v[st][i];
            if(dist[check]) continue;
            q.push(check);
            dist[check] = dist[st] + 1; 
        }
    }

    cout<<ans<<"\n";

    return 0;
}