#include <iostream>
#include <string.h>
using namespace std;

#define min(x,y) x<=y ? x : y
#define INF 987654321

int dp[1000001];

int solve(int n){
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];   // -1이 아니란건 방문을 했다는 뜻, -1이면 방문한 것

    int res = INF;
    if(n % 2 == 0) res = min(res, solve(n / 2) + 1);
    // if(n % 2 == 0) res = solve(n / 2) + 1;
    if(n % 3 == 0) res = min(res, solve(n / 3) + 1);
    if(n % 6 != 0){
        res = min(res, 1 + solve(n - 1));
    }
    // res = min(res, solve(n - 1) + 1);

    return dp[n] = res;
}

int main(){
    int N, count = 0;

    cin>>N;

    memset(dp, -1, sizeof(dp));
    
    cout<<solve(N);

}