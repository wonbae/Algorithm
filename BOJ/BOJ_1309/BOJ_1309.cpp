#include<bits/stdc++.h>
using namespace std;
#define MOD 9901

int dp[100001][3];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i <= n; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][0])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }

    cout<<(dp[n][0]+dp[n][1]+dp[n][2])%MOD<<"\n";

    return 0;
}