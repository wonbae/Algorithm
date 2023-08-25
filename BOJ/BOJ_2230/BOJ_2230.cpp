#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    ll n;
    ll m, mini = LLONG_MAX;

    cin>>n>>m;

    vector<ll> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    ll lp = 0, rp = 1;

    while(1){
        ll tmp = abs(v[rp] - v[lp]);

        if(tmp >= m){
            
            if(tmp < mini){
                mini = tmp;
            }

            if(tmp == m) break;

            lp++;

        }else{
            if(rp == n - 1) break;
            rp++;
        }
    }

    cout<<mini;

    return 0;
}