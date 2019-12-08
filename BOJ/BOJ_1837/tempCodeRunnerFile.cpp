#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    long long n;

    cin>>n>>k;

    vector<bool> isPrime(n+1, true);
    vector<int> prime;
    long long max = sqrt(n);

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i <= max; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = i*2; j <= n; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                }
            }
        }
    }

    for(int i = 0; i < prime.size(); i++){
        if(n % prime[i] == 0){
            long long tmp = n / prime[i];
            if(isPrime[tmp] && tmp > k && prime[i] > k){
                cout<<"GOOD"<<"\n";
            }else if(tmp <= k || prime[i] <= k ){
                cout<<"BAD"<<" "<<min(int(tmp),prime[i])<<"\n";
            }
        }
    }



    return 0;
}