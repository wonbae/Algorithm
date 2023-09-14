#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define INF 987654321

int dp[501][501];
int prefixSum[501];

int main(){
    fastio;

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }


        prefixSum[0] = v[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + v[i];
        }

        for(int dist = 1; dist < n; dist++){
            for(int startPos = 0; (startPos + dist) < n; startPos++){

                int endPos = startPos + dist;
                int psum = prefixSum[endPos] - prefixSum[startPos - 1];

                dp[startPos][endPos] = INF;

                // cout<<"dist: "<<dist<<", startPos: "<<startPos<<", endPos: "<<endPos<<"\n";

                for(int k = startPos; k < endPos; k++){
                    // cout<<"dp["<<startPos<<"]["<<k<<"] + "<<"dp["<<k+1<<"]["<<endPos<<"] + "<<psum<<"\n";
                    

                    dp[startPos][endPos] = min(dp[startPos][endPos], dp[startPos][k] + dp[k+1][endPos] + psum);
                    
                    // cout<<dp[startPos][k]<<"+"<<dp[k+1][endPos]<<"+"<<psum<<"\n";
                    // cout<<"dp["<<startPos<<"]["<<endPos<<"] = "<<dp[startPos][endPos]<<"\n\n";
                    
                }
                // cout<<"\n";

            }
            // cout<<"\n\n";
        }

        cout<<dp[0][n-1]<<"\n";
    }


    return 0;
}