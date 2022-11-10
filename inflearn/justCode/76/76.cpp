#include<iostream>
using namespace std;

int memo[21][21];

int binomial_distribution(int n, int r){
    if(memo[n][r] > 0) return memo[n][r];
    if(n == 0|| r == 0 || n == r) return 1;

    return memo[n][r] = binomial_distribution(n - 1, r - 1) + binomial_distribution(n - 1, r);
}

int main(){
    int n, c;
    cin>>n>>c;

    cout<<binomial_distribution(n, c)<<"\n";

    return 0;
}