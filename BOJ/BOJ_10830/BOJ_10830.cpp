#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define MOD 1000
typedef long long ll;
typedef vector<vector<ll>> Matrix;


Matrix matPower(Matrix A, Matrix B){
    ll s = A.size();
    
    Matrix C(s, vector<ll>(s,0));

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            for (int k = 0; k < s; k++) {
                C[i][j] = (C[i][j] + (A[i][k] % MOD) * (B[k][j] % MOD)) % MOD;
            }
        }
    }
    
    return C;
}


Matrix multiplyMatrix(Matrix& matrix, ll b){
    if(b <= 1){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                matrix[i][j] %= MOD;
            }
        }
        return matrix; 
    }
    else if(b % 2 == 0){
        Matrix half = multiplyMatrix(matrix, b/2);
        return matPower(half, half);
    }
    else{
        Matrix half = multiplyMatrix(matrix, (b-1)/2);
        return matPower(matPower(half, half), matrix);
    }
}


int main(){
    fastio;

    int N;
    ll B;

    cin>>N>>B;
    
    Matrix v(N, vector<ll>(N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>v[i][j];
        }
    }

    Matrix res = multiplyMatrix(v, B);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<res[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}