#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<ll, ll> > v(n);
    ll x,y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end());

    ll s = -INF, e = -INF;
    ll ans = 0;

    for(int i = 0; i < v.size(); i++){
        ll ns = v[i].first;
        ll ne = v[i].second;
        if(s <= ns && ne <= e) continue;

        ans += ne - ns;

        if(ns < e){
            ans -= e-ns;
        }
        
        s = ns;
        e = ne;
    }
    cout<<ans<<"\n";
    return 0;
}