#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000

long long binomialCoefficiant(int n, int k){
    long long C[SIZE + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = min(i, k); j > 0; j--){
            C[j] = (C[j] + C[j - 1]) % 10007;
        }
    }

    return C[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,K;

    cin>>N>>K;

    cout<<binomialCoefficiant(N, K)<<"\n";

    return 0;
}