#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, maxi=-2147483647;
    cin>>n>>k;

    vector<int> v(n,0);
    vector<int> preSum(n,0);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        
        if(i>0){
            preSum[i] = preSum[i-1] + v[i];
        }else preSum[0] = v[0];
    }

    for(int i = 0; i <= n-k; i++){
        int tmp = preSum[i+k-1] - preSum[i-1];
        if(tmp > maxi) maxi = tmp;
    }
    cout<<maxi;
    return 0;
}