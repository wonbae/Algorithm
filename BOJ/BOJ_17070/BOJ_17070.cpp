#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int v[24][24];
int dp[24][24][3];

bool check(int i, int j, int d){
    if(d == 0 || d == 2){
        if(!v[i][j]) return true;
    }else if(d == 1){
        if(v[i][j] == 0 && v[i-1][j] == 0 && v[i][j-1] == 0){
            return true;
        }
    }
    return false;
}

int main(){
    fastio;
    
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
        }
    }

    dp[0][1][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1)) dp[i+1][j+1][1] += dp[i][j][0];

            if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][2];
            if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][2];

            if(check(i+1, j, 2)) dp[i+1][j][2] += dp[i][j][1];
            if(check(i, j+1, 0)) dp[i][j+1][0] += dp[i][j][1];
            if(check(i+1, j+1, 1)) dp[i+1][j+1][1] += dp[i][j][1];
        }
    }

    int res = dp[n-1][n-1][0];
    res += dp[n-1][n-1][1];
    res += dp[n-1][n-1][2];

    cout<<res<<"\n";

    return 0;
}
