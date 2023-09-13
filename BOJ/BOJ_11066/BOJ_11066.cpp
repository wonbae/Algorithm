#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define INF 987654321

int dp[501][501];
int sumation[501];

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


        sumation[0] = v[0];
        for(int i = 1; i < n; i++){
            sumation[i] = sumation[i - 1] + v[i];
        }

        for(int far = 1; far < n; far++){
            for(int startPos = 0; (startPos + far) < n; startPos++){

                int endPos = startPos + far;
                int diff = sumation[endPos] - sumation[startPos - 1];

                dp[startPos][endPos] = INF;

                for(int k = startPos; k < endPos; k++){
                    dp[startPos][endPos] = min(dp[startPos][endPos], dp[startPos][k] + dp[k+1][endPos] + diff);
                }

            }
        }

        cout<<dp[0][n-1]<<"\n";
    }



    return 0;
}