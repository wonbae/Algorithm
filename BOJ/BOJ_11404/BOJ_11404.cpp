#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 4, vector<int>(n + 4, INF));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i==j){
                dist[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout<<0<<" ";
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
