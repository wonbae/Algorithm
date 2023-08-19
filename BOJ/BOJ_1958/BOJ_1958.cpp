#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int dp[104][104][104];

int main(){
    fastio;
    string str, str2, str3;
    cin>>str;
    cin>>str2;
    cin>>str3;

    int alen = str.size();
    int blen = str2.size();
    int clen = str3.size();

    for(int i = 0; i <= alen; i++){
        dp[i][0][0] = 0;
    }
    for(int i = 0; i <= blen; i++){
        dp[0][i][0] = 0;
    }
    for(int i = 0; i <= clen; i++){
        dp[0][0][i] = 0;
    }

    for(int i = 1; i <= alen; i++){
        for(int j = 1; j <= blen; j++){
            for(int k = 1; k <= clen; k++){
                if(str[i-1] == str2[j-1] && str2[j-1] == str3[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }


    // for(int i = 0; i <= alen; i++){
    //     for(int j = 0; j <= blen; j++){
    //         for(int k = 0; k <= clen; k++){
    //             cout<<dp[i][j][k]<<" ";
    //         }cout<<"\n";
    //     }cout<<"\n";
    // }

    cout<<dp[alen][blen][clen]<<"\n";

    return 0;
}