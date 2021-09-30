#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > pq;
    int n, ans = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        pq.push(num);
    }

    while(!pq.empty()){
        if(pq.size() == 1){
            break;
        }
        int front = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        ans += (front+second);
        pq.push(front+second);
    }

    cout<<ans<<"\n";
    return 0;
}