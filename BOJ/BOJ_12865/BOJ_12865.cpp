#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int dp[100001];

int main(){
    int n, k;
    cin>>n>>k;

    while(n--){
        int w,v;
        cin>>w>>v;
        // cout<<"\n";
        for(int j = k; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);

            // for(int i = 0; i < k+2; i++){
            //     cout<<dp[i]<<" ";
            // }cout<<"\n";
        }
    }

    cout<<dp[k];

    return 0;
}