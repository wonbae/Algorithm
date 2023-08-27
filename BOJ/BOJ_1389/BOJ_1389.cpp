#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> v(n+1, vector<int>(n+1, INF));

    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;

        v[a][b] = 1;
        v[b][a] = 1;
    }

    for(int i = 1; i <= n; i++){
        v[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(v[i][j] > 0)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout<<v[i][j]<<" ";
    //     }cout<<"\n";
    // }

    int sumation = INF;
    int idx = INF;

    for(int i = 1; i <= n; i++){
        int tmp = 0;
        for(int j = 1; j <= n; j++){
            tmp += v[i][j];
        }

        // cout<<tmp<<"\n";

        if(tmp < sumation){
            sumation = tmp;
            idx = i;
        }
    }

    cout<<idx;

    return 0;
}