#include<iostream>
using namespace std;
#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int n, m, dp[502][502], path[502], ans = 0;
    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INF;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        dp[a][b] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(dp[i][j] != INF){
                path[i]++;
                path[j]++;

                if(path[i] == n-1) ans++;
                if(path[j] == n-1) ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}