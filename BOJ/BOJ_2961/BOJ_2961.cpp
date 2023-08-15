#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastio;

    int n;
    cin>>n;
    ll res = 2147483647;

    vector<pair<ll, ll>> v;

    for(int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }

    for(int i = 1; i < (1<<n); i++){
        ll multi = 1;
        ll sumaiton = 0;

        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                // cout<<i<<", "<<j<<"\n";
                multi *= v[j].first;
                sumaiton += v[j].second;
            }
        }

        res = min(res, abs(multi-sumaiton));
    }

    cout<<res;
    return 0;
}