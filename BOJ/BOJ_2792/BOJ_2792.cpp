#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
typedef long long ll;
using namespace std;

ll arr[300001];
ll n, m, ans = 2147483647;

bool check(ll mid){
    ll num = 0;
    for(int i = 0; i < m; i++){
        num += arr[i] / mid;
        if(arr[i] % mid) num++;
    }

    return n >= num;
}

int main(){    
    fastio;
    cin>>n>>m;

    ll lo=1, hi=0;
    
    for(int i = 0; i < m; i++){
        cin>>arr[i];
        hi = max(hi, arr[i]);
    }

    while(lo <= hi){
        ll mid = lo + ((hi-lo) / 2);
        if(check(mid)){
            ans = min(ans, mid);
            hi = mid - 1;
        }else lo = mid + 1;
    }

    cout<<ans;
    return 0;
}