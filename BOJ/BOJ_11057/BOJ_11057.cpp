#include<iostream>
using namespace std;

#define mod 10007
int n, d[1001][10];
int ans = 0;
 
int main(void){
    cin >> n;
    for (int i = 0; i < 10; i++) d[1][i] = 1;

    for (int i = 2; i <= n; i++){
        for (int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                d[i][j] += d[i - 1][k];
            }
            d[i][j] %= mod;
        }
    }
    // for(int i = 0; i < 10; i ++){
    //     for(int j = 0; j < 10; j++){
    //         cout<<"i : "<<i<<", j : "<<j<<"->"<<d[i][j]<<endl;
    //     }
    // }
    for (int i = 0; i < 10; i++) ans += d[n][i]; 
    cout << ans % mod << "\n";
    return 0;
}