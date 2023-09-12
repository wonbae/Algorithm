#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;
    
    vector<int> v(100+1);
    vector<vector<ll> > dp(101, vector<ll>(20+1));

    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }
    
    dp[1][v[1]] = 1;

    int target = v[n];

    for(int i = 2; i < n; i++){
        for(int j = 0; j <= 20; j++){
            if(dp[i-1][j] == 0) continue;

            if(v[i] + j <= 20){
                dp[i][v[i] + j] += dp[i-1][j];
            }
            
            if(j - v[i] >= 0){
                dp[i][j - v[i]] += dp[i-1][j];
            }
        }
    }

    cout<<dp[n-1][target]<<"\n";

    return 0;
}