#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, dp[1001], arr[1001];
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > ans) ans = dp[i];
    }

    cout<<ans<<"\n";
    return 0;
    // int N, num, tmp = 0, res = 0;
    // cin>>N;

    // int dp[1001], v[1001];
    
    // for(int i = 0; i < N; i++){
    //     cin>>num;
    //     v[i] = num;
    //     tmp = 0;
    //     for(int j = 0; j < i; j++){
    //         if(v[j] < num){
    //             if(dp[j] > tmp){
    //                 tmp = dp[j];
    //             }
    //         }
    //     }
    //     dp[i] = tmp + 1;
    //     if(dp[i] > res){
    //         res = dp[i];
    //     }
    // }

    // cout<<res<<"\n";
    // return 0;
}