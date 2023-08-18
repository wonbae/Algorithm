#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]);
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }

    return dp[0][n - 1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> dims(n + 1);
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        dims[i] = r;
        if (i == n - 1) {
            dims[i + 1] = c;
        }
    }

    int minOperations = matrixChainMultiplication(dims);
    cout << minOperations << endl;

    return 0;
}
