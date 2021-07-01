#include<iostream>
#define max(a,b) (a>b)?a:b
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    int n, arr[1001], dp[1001], sum = 0, maxi = -2147000000;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = arr[i];
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(dp[i] > maxi) maxi = dp[i];
    }
    cout<<maxi<<"\n";

    return 0;
}