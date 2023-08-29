#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> memo; // Memoization table

// int dfs(int row, int col) {
//     if (row == M - 1 && col == N - 1) {
//         return 1; // Return 1 for reaching the target
//     }

//     if (memo[row][col] != -1) {
//         return memo[row][col]; // Return memoized result
//     }

//     int paths = 0;

//     // Define the four possible directions: up, down, left, right
//     int di[] = {-1, 1, 0, 0};
//     int dj[] = {0, 0, -1, 1};

//     for (int k = 0; k < 4; k++) {
//         int ni = row + di[k];
//         int nj = col + dj[k];
        
//         // Check if the new position is within bounds and the height is lower
//         if (ni >= 0 && ni < M && nj >= 0 && nj < N && map[ni][nj] < map[row][col]) {
//             paths += dfs(ni, nj);
//         }
//     }

//     // Store the result in the memoization table
//     memo[row][col] = paths;
//     return paths;
// }

int dfs(int row, int col) {
    if (row == M - 1 && col == N - 1) {
        return 1; // Return 1 for reaching the target
    }

    if (memo[row][col] != -1) {
        return memo[row][col]; // Return memoized result
    }

    memo[row][col] = 0; // Initialize with 0 before updating
    
    // Define the four possible directions: up, down, left, right
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int ni = row + di[k];
        int nj = col + dj[k];
        
        // Check if the new position is within bounds and the height is lower
        if (ni >= 0 && ni < M && nj >= 0 && nj < N && map[ni][nj] < map[row][col]) {
            memo[row][col] += dfs(ni, nj); // Update memoization table
        }
    }

    return memo[row][col]; // Return the memoized result
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    cin >> M >> N;

    map.assign(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    // Initialize the memoization table with -1
    memo.assign(M, vector<int>(N, -1));

    int numPaths = dfs(0, 0);
    cout << numPaths << endl;

    return 0;
}
