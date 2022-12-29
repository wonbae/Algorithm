#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n, p, d, ans = 0;
    vector<pair<int, int> > v;
    priority_queue<int, vector<int>, greater<int> > pq;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        cin>>p>>d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout<<ans<<"\n";
    return 0;
}