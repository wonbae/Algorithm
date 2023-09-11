#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009;
typedef long long ll;

ll dp[1000001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    dp[0] = 1;

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 1000000; j++){
            if(j - i >= 0){
                dp[j] = (dp[j-1] + dp[j-2] + dp[j-3]) % MOD;
            }
        }
    }

    int t;
    cin>>t;

    while(t--){
        int n; 
        cin>>n;

        cout<<dp[n]<<"\n";
    }


    return 0;
}