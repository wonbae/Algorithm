#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int n;
vector<int> v;
vector<vector<int>> dp;

int main() {
    fastio;
    
    int m;
    cin >> n;
    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp.resize(n + 1, vector<int>(n + 1, 0));

    // odd-length palindrome
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        while (l >= 1 && r <= n && v[l] == v[r]) {
            dp[l][r] = 1;
            l--;
            r++;
        }
    }

    // even-length palindrome
    for (int i = 1; i <= n - 1; i++) {
        int l = i, r = i + 1;
        while (l >= 1 && r <= n && v[l] == v[r]) {
            dp[l][r] = 1;
            l--;
            r++;
        }
    }

    cin >> m;

    int s, e;
    while (m--) {
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }

    return 0;
}
