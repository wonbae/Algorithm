#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100001];
ll cnt[100001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    ll n, lp=0, rp=0, ans=0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    while(rp<n){
        if(!cnt[arr[rp]]){
            cnt[arr[rp]]++;
            rp++;
        }else{
            ans+=(rp-lp);
            cnt[arr[lp]]--;
            lp++;
        }
    }

    ans += (rp-lp) * (rp-lp+1)/2;
    cout<<ans;

    return 0;
}