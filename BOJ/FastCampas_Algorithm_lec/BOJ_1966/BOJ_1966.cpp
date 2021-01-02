// 1. queue - 입력받은 우선순위와 index를 저장
// 2. priority_queue - 가장 우선순위인 것들 저장, 백터를 쓰던가

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;

    while(tc--){
        priority_queue<int> pq;
        queue<pair<int, int> > q;

        int n, index, cnt = 0;
        cin>>n>>index;

        for(int i = 0; i < n; i++){
            int prio;
            cin>>prio;
            q.push(make_pair(prio, i));
            pq.push(prio);
        }

        while(!q.empty()){
            int tprio = q.front().first;
            int idx = q.front().second;
            q.pop();

            if(tprio == pq.top()){
                cnt++;
                pq.pop();
                if(idx == index) break;
            }else{
                q.push(make_pair(tprio, idx));
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
