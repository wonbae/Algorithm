#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int N;
    cin >> N;

    dp[0] = 1;
    dp[1] = 1;

    if(N > 1) {
        for(int i=2; i<=N; i++)
            dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }

    cout << dp[N];
    return 0;
}

// #include <iostream>
// using namespace std;

// int dp[1001] = {0,1,3};

// int f(int n){
//     if(dp[n]) return dp[n];

//     return dp[n] = (f(n-1) % 10007 + 2 * f(n - 2) % 10007 ) % 10007;
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<f(n)<<endl;
//     return 0;
// }