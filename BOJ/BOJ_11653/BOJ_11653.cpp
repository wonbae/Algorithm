#include<bits/stdc++.h>
using namespace std;

#define LIM 10000

int main(){
    int n;
    cin>>n;

    int max = sqrt(n);
    vector<bool> isPrime(max + 1, true);
    vector<int> prime;

    if(n == 1) return 0;

    for(int i = 2; i <= max; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = 2*i; j<= max; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                }
            }
        }
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 0; i < prime.size(); i++){
        while(n % prime[i] == 0){
            
            cout<<prime[i]<<"\n";
            n /= prime[i];

        }
    }

    if(n > 1){
        cout<<n<<"\n";
    }

    return 0;
}