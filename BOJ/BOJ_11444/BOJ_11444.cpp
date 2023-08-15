#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;
// #define MOD 1000000007

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
const int MOD = int((1e9)+7);

Matrix matrixMultiply(Matrix A, Matrix B){
    Matrix C(2, vector<ll>(2,0));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            C[i][j] = (((A[i][0])%MOD * (B[0][j])%MOD) % MOD + ((A[i][1])%MOD * (B[1][j])%MOD) % MOD) % MOD;
        }
    }
    return C;
}

Matrix matrixPower(Matrix matrix, ll n){
    if(n <= 1){
        return matrix;
    }if(n % 2 == 0){
        Matrix half = matrixPower(matrix, n / 2);
        return matrixMultiply(half, half);
    }else{
        Matrix half = matrixPower(matrix, (n - 1) / 2);
        return matrixMultiply(matrix, matrixMultiply(half, half));
    }
}

ll fibonaci(ll num){
    if(num == 0) return 0;
    
    Matrix F{
        {1,1},
        {1,0}
    };

    Matrix leftup = matrixPower(F, num - 1);
    return leftup[0][0]; 
}

int main(){
    fastio;
    ll n, ans;
    cin>>n;

    ans = fibonaci(n) % MOD;
    
    cout<<ans % MOD<<"\n";
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// const int MOD = 1000000007;

// struct Matrix {
//     ll a, b, c, d;
//     Matrix(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}
//     Matrix operator*(const Matrix& other) const {
//         return Matrix(
//             (a * other.a + b * other.c) % MOD,
//             (a * other.b + b * other.d) % MOD,
//             (c * other.a + d * other.c) % MOD,
//             (c * other.b + d * other.d) % MOD
//         );
//     }
// };

// Matrix matrixPower(Matrix matrix, ll n) {
//     if (n == 1) {
//         return matrix;
//     }
//     if (n % 2 == 0) {
//         Matrix half = matrixPower(matrix, n / 2);
//         return half * half;
//     } else {
//         Matrix half = matrixPower(matrix, (n - 1) / 2);
//         return matrix * half * half;
//     }
// }

// ll fibonacci(ll n) {
//     if (n == 0) return 0;
//     Matrix F(1, 1, 1, 0);
//     Matrix result = matrixPower(F, n - 1);
//     return result.a;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     ll n;
//     cin >> n;

//     ll ans = fibonacci(n) % MOD;

//     cout << ans % MOD << "\n";
//     return 0;
// }
