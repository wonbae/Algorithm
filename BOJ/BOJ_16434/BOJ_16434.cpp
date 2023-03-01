#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
using namespace std;

ll n, Hatk;
ll curHP, maxHP, res;
vector<ll> t, a, h;

bool check(ll mid){
    maxHP = mid;
    curHP = mid;
    ll atk = Hatk;

    for(int i = 0; i < n; i++){
        if(t[i] == 1){
            ll iter;
            if(h[i] % atk == 0){
                iter = h[i] / atk;
            }else iter = h[i] / atk + 1;

            if((iter - 1) * a[i] >= curHP) return false;
            curHP -= ((iter - 1) * a[i]);
        }else{
            atk += a[i];
            curHP = min(curHP + h[i], maxHP);
        }
    }
    return curHP >= 1 ? true : false;
}


int main(){
    fastio;
    cin>>n>>Hatk;

    for(int i = 0; i < n; i++){
        ll ti, ai, hi;
        cin>>ti>>ai>>hi;
        t.push_back(ti);
        a.push_back(ai);
        h.push_back(hi);
    }

    ll lo = 1;
    ll hi = 1e18 + 4;

    while(lo <= hi){
        ll mid = lo + ((hi - lo) / 2);
        if(check(mid)){
            res = mid;
            hi = mid - 1;
        }else lo = mid + 1;
    }

    cout<<res<<"\n";

    return 0;
}