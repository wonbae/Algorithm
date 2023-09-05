#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000007;
int dp[51][51][51][51];
int v[51][51];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int n, m, c;
    cin>>n>>m>>c;

    int a, b;
    for(int i = 1; i <= c; i++){
        cin>>a>>b;
        v[a][b] = i;
    }

    if(v[1][1] != 0){
        dp[1][1][1][v[1][1]] = 1;
    }else{
        dp[1][1][0][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int game = v[i][j];
    
            if(game != 0){
                for(int num = 0; num <= game; num++){
                    for(int visit = 0; visit <= num; visit++){
                        dp[i][j][visit+1][game] += (dp[i-1][j][visit][num] + dp[i][j-1][visit][num]) % MOD;
                    }
                }
            }else{
                for(int num = 0; num <= c; num++){
                    for(int visit = 0; visit <= num; visit++){
                        dp[i][j][visit][num] += (dp[i-1][j][visit][num] + dp[i][j-1][visit][num]) % MOD;
                    }
                }
            }
        }
    }

    for(int i = 0; i <= c; i++){
        int tmp = 0;
        for(int j = 0; j <= c; j++){
            tmp += dp[n][m][i][j];
        }
        cout<<tmp%MOD<<" ";
    }

    return 0;
}