#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
typedef long long ll;
using namespace std;

ll s, c, res, sum, cnt;
vector<ll> v;

bool check(ll mid){
    cnt = 0;
    for(int i = 0; i < s; i++){
        cnt += (v[i] / mid);
    }
    return cnt >= c;
}

int main(){
    fastio;
    cin>>s>>c;    
    v.resize(s);
    
    for(int i = 0; i < s; i++){
        cin>>v[i];
        sum += v[i];
    }

    ll l = 1, r = 1e9;
    while(l <= r){
        ll mid = l + ((r - l) / 2);
        
        if(check(mid)){
            l = mid + 1;
            res = mid;
        }else{
            r = mid - 1;
        }
    }
    cout<<sum - res * c<<"\n";
    return 0;
}