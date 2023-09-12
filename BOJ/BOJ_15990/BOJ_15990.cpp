#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009
#define MAX 100000
typedef long long ll;

ll dp[MAX+1][4];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    dp[1][1] = 1;   dp[2][1] = 0;   dp[3][1] = 1;
    dp[1][2] = 0;   dp[2][2] = 1;   dp[3][2] = 1;
    dp[1][3] = 0;   dp[2][3] = 0;   dp[3][3] = 1;

    for(int i = 4; i <= MAX; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }

    int t;
    cin>>t;

    while(t--){
        int n; 
        cin>>n;

        cout<<(dp[n][1] + dp[n][2] + dp[n][3])%MOD << "\n";
    }


    return 0;
}