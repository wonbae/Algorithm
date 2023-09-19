#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int dp[1004];

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1);

    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i] = INF;
    }
    
    dp[1] = v[1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            // cout<<"min(dp["<<i<<"], dp["<<i<<"-"<<j<<"] + v["<<j<<"] = dp["<<i<<"]\n";
            // cout<<dp[i]<<", "<<dp[i-j]<< "+" << v[j]<<"\n";

            dp[i] = min(dp[i], dp[i - j] + v[j]);

            // cout<<dp[i]<<"\n";
        }
        // cout<<"\n";
    }

    cout<<dp[n]<<"\n";

    return 0;
}