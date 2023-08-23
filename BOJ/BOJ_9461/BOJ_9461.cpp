#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 3] + dp[i - 2];
        }

        // for(int i = 0; i < n; i++){
        //     cout<<dp[i]<<" ";
        // }cout<<"\n";

        cout<<dp[n-1]<<"\n";
    }
    return 0;
}