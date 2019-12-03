// #include<bits/stdc++.h>
// using namespace std;

// bool prime(int n){
//     if(n <= 1) return false;
//     // int pr[] = {2,3,5,7,11};
//     for(int i = 2; i * i <= n; i++){
//         if(n % i == 0){
//             return false;
//         }
//     }

//     return true;
// }

// int main(){
//     int n,m;
//     cin>>m>>n;

//     for(int i = m; i <= n; i++){

//         if(prime(i)){

//             cout<<i<<"\n";
//         }
//     }
    
//     return 0;
// }

// #include <bits/stdc++.h>
 
// using namespace std;

// bool prime(int n, bool *isPrime){
//     for(int i = 2; i*i <= n; i++){
//         if(n % i == 0){
//             for(int j = i * i; j * j <= 1000000; j += i){
//                 isPrime[j] = false;
//             }
//             return false;
//         }
//     }

//     return true;
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
 
//     bool isPrime[1000000];
//     memset(isPrime, true, sizeof(isPrime));

//     int num, num2;

//     cin>>num>>num2;

//     // 에라토스테네스의 체 이용하여 1,000,000까지의 소수 구하기
//     isPrime[0] = false;
//     isPrime[1] = false;

//     for(int i = num; i <= num2; i++){
//         if(prime(i, isPrime)){
//             cout<<i<<"\n";
//         }
//     }
 
//     return 0;
// }

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int M, N;
    cin >> M >> N;
    vector<bool> isPrime(N + 1, true); 

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i*i <= N; i++) {
        if (isPrime[i]) {
            // 소수의 J배수들은 모두 소수가 아님
            for (int j = 2 * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
 
    for(int i = M; i <= N; i++)
        if(isPrime[i])
            cout << i << '\n';
 
    return 0;
}