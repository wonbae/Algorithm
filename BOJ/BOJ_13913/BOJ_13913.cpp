#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL);

int visited[100000];
int from[100000];

void output(int a, int b){
    if(a != b) output(a, from[b]);
    cout<<b<<" ";
}

int main(){
    FASTIO;
    int N, K, res;
    cin>>N>>K;
    queue<int> q;

    q.push(N);
    visited[N] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(now == K){
            res = visited[K]-1;
            break;
        }

        for(auto next : {now-1, now+1, now*2}){
            if(next < 0 || next > 100000) continue;
            if(visited[next] == 0){
                q.push(next);
                visited[next] = visited[now] + 1;   
                from[next] = now;
            }else if(visited[next] == visited[now]+1){
                from[next] = now;
            }
        }
    }

    cout<<res<<"\n";
    output(N,K);

    return 0;
}