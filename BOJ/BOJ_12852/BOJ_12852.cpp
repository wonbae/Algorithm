#include<bits/stdc++.h>
using namespace std;

int dp[1000001];
int mem[1000001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int x;
    cin>>x;

    dp[1] = 0;
    memset(mem, -1, sizeof(mem));

    for(int i = 2; i <= x; i++){
        dp[i] = dp[i - 1] + 1;
        mem[i] = i - 1;

        if((i % 2 == 0) && (dp[i] > dp[i/2] + 1)){
            dp[i] = dp[i/2] + 1;
            mem[i] = i/2;
        }

        if((i % 3 == 0) && (dp[i] > dp[i/3] + 1)){
            dp[i] = dp[i/3] + 1;
            mem[i] = i/3;
        }
    }

    cout<<dp[x]<<"\n";
    cout<<x<<" ";

    while(mem[x] != -1){
        cout<<mem[x]<<" ";
        x = mem[x];
    }

    return 0;
}