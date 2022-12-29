#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, dp[10001];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL), cout.tie(NULL);
    ll num;
    cin>>t;
    dp[0] = 1;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 10000; j++){
            if(j-i>=0){
                dp[j] += dp[j-i];
            }
        }
    }
    while(t--){
        cin>>num;
        cout<<dp[num]<<"\n";
    }
    return 0;
}