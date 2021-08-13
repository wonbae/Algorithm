#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, p, d, sum = 0;
    cin>>n;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    for(int i = 0; i < n; i++){
        cin>>p>>d;
        pq.push(make_pair(d,p));
    }

    int before = 0, cnt = 0;

    while(!pq.empty()){
        int day = pq.top().first;
        int pay = pq.top().second;
        pq.pop();

        if(before == day){
            continue;
        }else{
            if(cnt <= day){
                sum += pay;
                before = day;
                cnt++;
            }
        }
    }
    cout<<sum<<"\n";
    return 0;
}