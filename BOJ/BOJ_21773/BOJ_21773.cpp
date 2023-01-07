// 1. 실행시킬 프로세스를 기준에 따라 선택합니다. 선택된 프로세스의 id를 ids라 합니다. ids를 실행시킵니다.
// 2. 1초가 지난 후, 프로세스 id가 ids인 프로세스를 제외한 나머지 프로세스들의 우선 순위가 1 상승합니다. 
// 프로세스 id가 ids 인 프로세스의 실행을 마치는 데 필요한 시간은 1 감소합니다.
// 3. 실행 시간이 남은 프로세스가 있다면 1로 돌아가고, 그렇지 않으면 종료합니다.

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct info{
    int id, time, prio;
    info(int c, int a, int b){
        id = a;
        time = b;
        prio = c;
    }
    
};

struct comp{
    bool operator()(const info& a1, const info& a2){
        if(a1.prio == a2.prio){
            return a1.id > a2.id;
        }
        return a1.prio < a2.prio;
    }
};

int main(){
    fastio;
    priority_queue<info, vector<info>, comp> pq;
    int t, n, a, b, c;
    cin>>t>>n;

    for(int i = 0; i < n; i++){
        cin>>a>>b>>c;
        pq.push(info(c, a, b));
    }

    while(t--){
        info tmp = pq.top();
        pq.pop();
        
        cout<<tmp.id<<"\n";

        if(tmp.time - 1 > 0){
            pq.push(info(tmp.prio-1, tmp.id, tmp.time-1));
        }
    }
    return 0;
}