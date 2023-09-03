// BOJ 2133
#include <iostream>
using namespace std;

// Function to calculate the number of ways to fill the wall
long long countWaysToFillWall(int N) {
    if (N % 2 == 1) {
        // If N is odd, there are no ways to fill the wall
        return 0;
    }

    long long dp[N + 1];

    // Initialize DP array
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    // Fill the DP array for each column
    for (int i = 4; i <= N; i += 2) {
        // Calculate dp[i] based on the number of ways to fill the current section

        // dp[i] = dp[i - 2] * 3 (vertical 2×1 tiles) + dp[i - 4] * 2 + dp[i - 2] (horizontal 1×2 tiles)
        dp[i] = dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;

    // Calculate the number of ways to fill the 3×N wall
    long long ways = countWaysToFillWall(N);

    // Output the result
    cout << ways << endl;

    return 0;
}
