#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, k;
vector<pair<int, int> > jw;
vector<int> bag;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin>>n>>k;
    
    jw.resize(n);
    bag.resize(k);

    for(int i = 0; i < n; i++){
        cin>>jw[i].first>>jw[i].second;
    }
    for(int i = 0; i < k; i++){
        cin>>bag[i];
    }

    sort(jw.begin(), jw.end());
    sort(bag.begin(), bag.end());

    int idx = 0;
    long long int ans = 0;

    for(int i = 0; i < k; i++){
        while(idx < n && jw[idx].first <= bag[i]){
            pq.push(jw[idx].second);
            idx++;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<"\n";

    return 0;
}