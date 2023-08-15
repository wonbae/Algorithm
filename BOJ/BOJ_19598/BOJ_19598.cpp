#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// struct CompareSecond{
//     bool operator()(const pair<int, int>& a, pair<int, int>& b){
//         return a.second > b.second;
//     }
// };

int main(){
    fastio;

    int n, s, e, room = 1;
    cin>>n;

    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++){
        cin>>s>>e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    
    pq.push(v[0].second);

    for(int i = 1; i < n; i++){
        if(pq.top() <= v[i].first)
            pq.pop();
        pq.push(v[i].second);
    }

    cout<<(int)pq.size();
    return 0;
}