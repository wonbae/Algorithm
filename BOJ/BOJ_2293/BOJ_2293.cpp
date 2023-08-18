#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int coins[104];
int dp[10004];

int main() {
    fastio;

    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = coins[i]; j <= k; j++){
            dp[j] += dp[j - coins[i]];
            // cout<<dp[j]<<", ";
        }
        // cout<<"\n";
    }

    cout<<dp[k];

    return 0;
}
