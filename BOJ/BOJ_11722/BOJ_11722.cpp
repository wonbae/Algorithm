#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1, 0);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[j] > v[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout<<dp[i]<<" ";
    // }

    cout<<*max_element(dp.begin(), dp.end());

    return 0;
}