#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0), cin.tie(NULL);
int visited[100004];
long long cnt[100004];

int main(){
    FAST_IO
    int n, k;
    queue<int> q;
    cin>>n>>k;

    if(n==k){
        cout<<0<<"\n"<<1;
        return 0;
    }

    visited[n] = 1;
    cnt[n] = 1;

    q.push(n);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int next : {now-1, now+1, 2*now}){
            if(next >= 0 && next <= 100000){
                if(visited[next] == 0){
                    q.push(next);
                    visited[next] = visited[now]+1;
                    cnt[next] += cnt[now];
                }else if(visited[next] == visited[now]+1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout<<visited[k] - 1<<"\n";
    cout<<cnt[k]<<"\n";


    return 0;
}