#include<bits/stdc++.h>
using namespace std;
#define MOD 15746

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> dp(1000001);
    
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= 1000000; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout<<dp[n]%MOD<<"\n";

    return 0;
}