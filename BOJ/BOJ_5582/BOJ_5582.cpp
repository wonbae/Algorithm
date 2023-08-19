#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int dp[4004][4004];

int main(){
    fastio;

    string str, str2;
    cin>>str>>str2;

    int alen = str.size();
    int blen = str2.size();

    for(int i = 0; i <= alen; i++) dp[i][0] = 0;
    for(int i = 0; i <= blen; i++) dp[0][i] = 0;

    int ans = 0;

    for(int i = 1; i <= alen; i++){
        for(int j = 1; j <= blen; j++){
            if(str[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                
                ans = max(ans, dp[i][j]);
            }
            // else{
            //     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            // }
        }
    }

    // for(int i = 0; i <= alen; i++){
    //     for(int j = 0; j <= blen; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }

    cout<<ans<<endl;
    
    return 0;
}