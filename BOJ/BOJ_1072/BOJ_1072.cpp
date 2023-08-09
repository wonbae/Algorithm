#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
using namespace std;

int main(){
    fastio;
    ll a, b, z, res = 0;
    cin>>a>>b;
    z = (b * 100 / a);

    ll l = 0, r = 1e9;

    while(l <= r){
        ll mid = l + ((r - l) / 2);
        if((mid + b) * 100 / (mid + a) > z){
            res = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout<<(res ? res : -1)<<"\n";
    return 0;
}