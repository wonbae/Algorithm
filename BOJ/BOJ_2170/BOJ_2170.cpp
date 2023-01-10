#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n;
    cin>>n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());


    int st = v[0].first, en = v[0].second;
    long long ans = en - st;

    for(int i = 1; i < v.size(); i++){
        if(v[i].first < en && v[i].second <= en) continue;
        else if(v[i].first < en && v[i].second > en){
            ans += v[i].second - en;
            en = v[i].second;
        }else if(v[i].first == en){
            ans += v[i].second - en; 
            en = v[i].second;
        }else{
            st = v[i].first;
            en = v[i].second;
            ans += en - st;
        }
        // cout<<st<<", "<<en<<" = "<<ans<<"\n";
    }

    cout<<ans;
    return 0;
}