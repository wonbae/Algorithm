#include<bits/stdc++.h>
#define MOD 1234567891
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;

int main(){
    fastio;
    ll n, a, r = 1, ans = 0;
    string str;

    cin>>n>>str;

    for(ll i = 0; i < str.size(); i++){
        a = ((str[i] - 'a') + 1) % MOD;
        ans += ((a * (r%MOD)) % MOD);
        r *= 31;
        if(r * 31 > MOD) r = r % MOD;
    }

    cout<<ans%MOD;

    return 0;
}