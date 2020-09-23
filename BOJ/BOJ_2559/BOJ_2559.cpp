#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, maxi = -2147000000, sum = 0;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(i < k){
            sum += v[i];
        }
    }

    dp[0] = sum;
    if(maxi < sum) maxi = sum;

    for(int i = 0; i < n - k; i++){
        sum = dp[i] - v[i];
        dp[i + 1] = sum + v[i + k];
        if(dp[i + 1] > maxi) maxi = dp[i + 1];
    }

    cout<<maxi<<"\n";

    return 0;
}