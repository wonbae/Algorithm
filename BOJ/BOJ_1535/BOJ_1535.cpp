#include<bits/stdc++.h>
using namespace std;

int dp[101];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> hp(n, 0);
    vector<int> emo(n, 0);
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++){
        cin>>hp[i];
    }

    for(int i = 0; i < n; i++){
        cin>>emo[i];
    }

    for(int i = 0; i < n; i++){
        // cout<<hp[i]<<", "<<emo[i]<<"\n";
        for(int j = 100; j > hp[i]; j--){
            dp[j] = max(dp[j], dp[j - hp[i]] + emo[i]);
        }
    }

    cout<<dp[100];

    return 0;
}