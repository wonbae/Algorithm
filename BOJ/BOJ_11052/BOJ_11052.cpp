#include<bits/stdc++.h>
using namespace std;

int dp[10001];

int main(){
    int n;
    cin>>n;

    vector<int> v(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }

    dp[1] = v[1];
    dp[2] = max(v[2], v[1]+v[1]);

    for(int i = 3; i <= n; i++){
        dp[i] = v[i];
        for(int j = 1; j <= (i/2+1); j++){
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        // cout<<dp[i]<<" ";
        ans = max(ans, dp[i]);
    }

    cout<<ans<<"\n";

    return 0;
}