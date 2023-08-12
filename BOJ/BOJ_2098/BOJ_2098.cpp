#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 987654321;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0] ? graph[pos][0] : INF;
    }

    int& ret = dp[mask][pos];
    if(ret != -1) return ret;

    ret = INF;


    for (int next = 0; next < n; ++next) {
        if(graph[pos][next] == 0) continue;

        if (!(mask & (1 << next))) {
            ret = min(ret, tsp(mask | (1<<next), next) + graph[pos][next])    ;
            // int newCost = graph[pos][next] + tsp(mask | (1 << next), next);
            // ans = min(ans, newCost);
        }
    }

    return ret;
}

int main() {
    cin >> n;

    graph.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    dp.resize(1 << n, vector<int>(n, -1));
    int result = tsp(1, 0);

    cout << result << endl;

    return 0;
}
