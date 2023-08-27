#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int min(int a, int b, int c){
    return (a > b) ? (b > c) ? c : b : (a > c) ? c : a;
}

int main(){
    fastio;

    int n, m, ans = 0;
    cin>>n>>m;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        for(int j = 0; j < m; j++){
            dp[i][j] = s[j] - '0';
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] != 0){
                dp[i][j] += min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
            }
            ans = max(ans, dp[i-1][j-1]);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         ans = max(ans, dp[i][j]);
    //         // cout<<dp[i][j]<<" ";
    //     }
    //     // cout<<"\n";
    // }
    
    cout<<ans*ans<<"\n";

    return 0;
}