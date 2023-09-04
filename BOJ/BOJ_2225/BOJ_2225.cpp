#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int N, K;
    cin>>N>>K;

    vector<vector<ll> > dp(N+1, vector<ll>(K+1, 0));

    for(int i = 0; i <= N; i++){
        dp[i][1] = 1;
    }

    for(int i = 0; i <= N; i++){
        for(int j = 2; j <= K; j++){
            for(int x = 0; x <= i; x++){
                dp[i][j] += (dp[i - x][j - 1] % MOD);
            }
        }
    }

    cout<<dp[N][K] % MOD<<"\n";


    return 0;
}