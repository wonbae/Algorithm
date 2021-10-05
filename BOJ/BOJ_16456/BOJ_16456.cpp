#include<iostream>
using namespace std;

const long long MOD = 1e9+9;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n;
    cin>>n;
    long long arr[50001] = {0,};

    arr[1] = arr[2] = arr[3] = 1;
    
    for(int i = 4; i <= n; i++){
        arr[i] = (arr[i-1] + arr[i-3])%MOD;
    }

    cout<<(n >= 2 ? (arr[n]+arr[n-2])%MOD : arr[n]);
    return 0;
}