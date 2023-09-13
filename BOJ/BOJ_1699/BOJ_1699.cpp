#include<bits/stdc++.h>
using namespace std;
#define MAXINT 100000
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> dp(MAXINT+1, 0);
    

    for(int i = 1; i <= MAXINT; i++){
        dp[i] = i;
    }

    for(int i = 4; i <= MAXINT; i++){ 
        for(int j = 2; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }

    
    cout<<dp[n]<<"\n";

    return 0;
}