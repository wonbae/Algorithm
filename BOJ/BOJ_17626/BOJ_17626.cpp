#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAXINT 50005
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int dp[MAXINT];

int main(){
    fastio;
    
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        dp[i] = INF;
        for(int j = 1; j * j <= i; j++){
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout<<dp[n];

    return 0;
}