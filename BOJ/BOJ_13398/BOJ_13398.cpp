#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(2, 0));

    dp[0][0] = v[0]; 
    dp[0][1] = v[0];
    long long ans = v[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max((long long)0, dp[i-1][0]) + v[i];    // 제거하지 않고 전체 중에 가장 큰 연속된 부분수열
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + v[i]);
        
        ans = max(dp[i][0], ans);
        ans = max(dp[i][1], ans);
    }

    cout<<ans<<"\n";    

    return 0;
}
