#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int dist[200004];

int main(){
    int n, k, ans=2147000000, cnt=0;
    cin>>n>>k;

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        vector<int> v;
        v.push_back(now-1);
        v.push_back(now+1);
        v.push_back(now*2);

        for(int i = 0; i < 3; i++){
            int nxt = v[i];
            
            if(nxt < 0 || nxt > 200004) continue;
            if(dist[nxt] < 0){
                q.push(nxt);
                dist[nxt] = dist[now] + 1;
            }
        }
    }
    cout<<dist[k];
    return 0;
}