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
            dp[i] = (dp[i-1]+dp[i-2]) % 10007;
    }

    cout << dp[N];
    return 0;
}




// 시간초과
// #include <iostream>
// using namespace std;

// int res;

// int dp(int n){
//     if(n == 1 || n == 0){
//         return 1;
//     }
     
//     res = dp(n - 1) + dp(n - 2);

//     return res % 10007;
// }
// int main(){
//     int N;
//     cin>>N;
//     cout<<dp(N)<<endl;

//     return 0;
// }