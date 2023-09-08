#include <iostream>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

ll dp[31][31];
 
int main() {
    fastio;

    for(int w = 0; w < 31; w++){
        for(int h = 0; h < 31; h++){
            if(w < h) continue;
            dp[0][0] = 1;

            dp[w][h] = dp[w-1][h] + dp[w][h-1];
        }
    }

    int n;
    while(cin>>n && n != 0){
        
        cout << dp[n][n] << "\n";

        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
    }
}
