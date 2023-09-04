#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> stickers(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n, 0));

        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < n; col++) {
                cin >> stickers[row][col];
            }
        }

        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];

        for (int col = 1; col < n; col++) {
            // Calculate the maximum score for stickers that do not share an edge with the previous sticker
            dp[0][col] = max(dp[0][col - 1], dp[1][col - 1] + stickers[0][col]);

            dp[1][col] = max(dp[1][col - 1], dp[0][col - 1] + stickers[1][col]);

        }

        // cout<<T<<"\n";
        // for(int i = 0; i < n; i++){
        //     cout<<dp[0][i]<<" ";
        // }cout<<"\n";
        // for(int i = 0; i < n; i++){
        //     cout<<dp[1][i]<<" ";
        // }cout<<"\n\n";

        // The answer is the maximum of the last two values in the dynamic programming table
        int answer = max(dp[0][n - 1], dp[1][n - 1]);
        cout << answer << endl;
    }

    return 0;
}
