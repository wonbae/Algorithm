#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int N,K,ans = 0;
    cin>>N>>K;
    deque<pair<int, int> > dq;
    bool visit[100001]={0,};
    
    dq.push_back(make_pair(N, 0));

    while(!dq.empty()){
        int now = dq.front().first;
        int second = dq.front().second;
        dq.pop_front();

        if(now == K){
            ans = second;
            break;
        }

        if(now > 1e5 || now < 0) continue;
        if(visit[now]) continue;
        visit[now] = true;
        
        dq.push_back(make_pair(now - 1, second+1));
        dq.push_back(make_pair(now + 1, second+1));
        if(now < K)
            dq.push_front(make_pair(now*2, second));
    }

    cout<<ans<<"\n";

    return 0;
}