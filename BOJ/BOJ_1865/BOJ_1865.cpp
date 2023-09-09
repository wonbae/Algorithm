#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);

const int INF = 987654321;
struct info {
    int to;
    int cost;
};

vector<int> dist;

void bellmanFord(vector<info> graph[], int v) {
    // vector<int> dist(v+1, INF);
    
    for(int i = 1; i <= v; i++){
        for (int u = 1; u <= v; u++) {
            for (auto& edge : graph[u]) {
                int next = edge.to;
                int weight = edge.cost;

                if (dist[u] + weight < dist[next]) {
                    dist[next] = dist[u] + weight;

                }
            }
        }
    }

    for (int u = 1; u <= v; u++) {
        for (auto& edge : graph[u]) {
            int next = edge.to;
            int weight = edge.cost;

            if (dist[u] + weight < dist[next]) {
                cout<<"YES\n";
                return;
            }
        }
    }

    cout<<"NO\n";
    return;
}


int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        int V, E, W;
        cin >> V >> E >> W;

        vector<info> node[501];

        for (int i = 0; i < E; i++) {
            int start, end, edge;
            cin >> start >> end >> edge;

            node[start].push_back({ end, edge });
            node[end].push_back({ start, edge });
        }
        

        for (int i = 0; i < W; i++) {
            int start, end, edge;
            cin >> start >> end >> edge;

            node[start].push_back({ end, -edge });
        }


        dist.resize(501, INF);
        
        bellmanFord(node, V);
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<pair<pair<int, int>, int>> v;
// int dist[501];

// void bellmanFord(int n) {
//     for (int i = 0; i < n; i++) {
//         for (int pos = 0; pos < v.size(); pos++) {
//             int from = v[pos].first.first;
//             int to = v[pos].first.second;
//             int cost = v[pos].second;

//             if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
//         }
//     }

//     for (int pos = 0; pos < v.size(); pos++) {
//         int from = v[pos].first.first;
//         int to = v[pos].first.second;
//         int cost = v[pos].second;
//         if (dist[from] + cost < dist[to]) {
//             cout << "YES\n";
//             return;
//         }
//     }

//     cout << "NO\n";

// }


// int main() {

//     int tc; cin >> tc;

//     while (tc--) {
//         v.clear();
//         int n, m, w; cin >> n >> m >> w;
//         for (int i = 1; i <= n; i++) dist[i] = 987654321;

//         for (int i = 0; i < m; i++) {
//             int from, to, cost; cin >> from >> to >> cost;
//             v.push_back({ {from,to},cost });
//             v.push_back({ {to,from},cost });
//         }
//         for (int i = 0; i < w; i++) {

//             int from, to, cost; cin >> from >> to >> cost;
//             v.push_back({ {from,to},-cost });
//         }

//         bellmanFord(n);
//     }


//     return 0;
// }