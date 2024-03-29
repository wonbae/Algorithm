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

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i - j] + v[j]);
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