#include<bits/stdc++.h>
using namespace std;

#define INF 2147000000;
const int dice[] = {1,2,3,4,5,6};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, m, ans = INF;
    cin>>n>>m;

    map<int, int> updown;

    for(int i = 0; i < n+m; i++){
        int u, v;
        cin>>u>>v;
        updown[u] = v;
    }
    
    vector<bool> visited(101, false);
    queue<pair<int, int>> q;
    q.push({1,0});
    visited[1] = true;

    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        // cout<<now<<"\t"<<cnt<<"\n";

        if(now == 100){
            ans = min(ans, cnt);
            break;
        }

        for(int i = 0; i < 6; i++){
            int next = now + dice[i];
            
            if(next > 100) continue;
            if(visited[next]) continue;
            
            if(updown.find(next) != updown.end()){
                next = updown[next];
                q.push({next, cnt+1});
                visited[next] = true;
            }else{
                q.push({next, cnt+1});
                visited[next] = true;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}