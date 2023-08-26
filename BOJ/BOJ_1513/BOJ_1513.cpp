#include<bits/stdc++.h>
using namespace std;
int INF = 987654321;
int dp[100001];

int main(){
    int n;
    cin>>n;

    dp[0] = 0;

    vector<int> coins;
    coins.push_back(2);
    coins.push_back(5);

    // Initialize dp array
    for (int i = 1; i <= n; i++) {
        dp[i] = INF; // Initialize with a large value
    }
    dp[0] = 0;

    for(int i = 0; i <= n; i++){
        for(auto coin : coins){
            if(coin <= i)
               dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    if(dp[n] == INF) {
        cout << -1;
    } else {
        cout << dp[n];
    }

    return 0;
}
