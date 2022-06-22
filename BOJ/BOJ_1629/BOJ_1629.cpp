#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a, b, c;

ll solve(ll a, ll b){
    if(b == 1) return a%c;
    ll tmp = solve(a, b/2);
    tmp = (tmp * tmp) % c;
    if(b%2) tmp = (tmp * a) % c;
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>a>>b>>c;
    ll ans = solve(a,b);
    cout<<ans;
    return 0;
}

    