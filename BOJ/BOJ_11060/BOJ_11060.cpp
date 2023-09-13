#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n+1);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    vector<int> dp(n+1, 987654321);

    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= min(n - 1, i + v[i]); j++){
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }


    if(dp[n-1] != 987654321){
        cout<<dp[n-1]<<"\n";
    }else{
        cout<<-1<<"\n";
    }


    return 0;
}