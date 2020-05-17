#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int N, num, tmp = 0, res = 0;
    cin>>N;

    int dp[1001], v[1001];
    
    for(int i = 0; i < N; i++){
        cin>>num;
        v[i] = num;
        tmp = 0;
        for(int j = 0; j < i; j++){
            if(v[j] < num){
                if(dp[j] > tmp){
                    tmp = dp[j];
                }
            }
        }
        dp[i] = tmp + 1;
        if(dp[i] > res){
            res = dp[i];
        }
    }

    cout<<res<<"\n";
    return 0;
}