#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define INF INT_MAX

int main(){
    fastio;

    int n, k;
    cin>>n>>k;

    vector<int> coins(n);
    vector<int> dp(k+1, INF);

    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    dp[0] = 0;

    for(int i = 1; i <= k; i++){
        for(int coin : coins){
            if((i - coin >= 0) && (dp[i - coin] != INF)){
                dp[i] = min(dp[i], dp[i - coin] + 1);
                // cout<<i<<","<<dp[i]<<"\t";
            }
        }
        // cout<<"\n";
    }

    cout<<(dp[k] == INF ? -1 : dp[k])<<"\n";

    return 0;
}