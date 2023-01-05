#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(flase) cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int n, ans = 0, s, e;
    vector<pair<int, int> > v;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>s>>e;
        v.push_back({s,e});
    }
    
    sort(v.begin(), v.end(), cmp);

    int tmp=0;
    for(int i = 0; i < v.size(); i++){
        if(tmp <= v[i].first){
            tmp = v[i].second;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}