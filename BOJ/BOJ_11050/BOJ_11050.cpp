#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000

int binomialCoefficiant(int n, int k){
    if(n == k || k == 0) return 1;
    return binomialCoefficiant(n - 1, k) + binomialCoefficiant(n - 1, k - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,K;

    cin>>N>>K;

    cout<<binomialCoefficiant(N, K)<<"\n";

    return 0;
}