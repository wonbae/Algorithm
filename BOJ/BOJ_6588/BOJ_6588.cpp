#include <bits/stdc++.h>
using namespace std;

#define LIMIT 1000000

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<bool> isPrime(LIMIT + 1, true);

    for(int i = 2; i*i <= LIMIT; i++){
        if(isPrime[i]){
            for(int j = (i * 2); j <= LIMIT; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                }
            }
        }
    }
    
    isPrime[0] = false;
    isPrime[1] = false;

    int n;

    while(1){
        cin>>n;

        if(n == 0){ return 0; }

        int rest = 0;

        // for(int i = 3; i < n; i++){}

        for(int i = 3; (i * 2) <= n; i += 2){
            if(isPrime[i]){
                if(i == n){
                    cout<<"Goldbach's conjecture is wrong.\n";
                    break;
                }else{
                    rest = n - i;
                    if(isPrime[rest]){
                        cout<<n<<" = "<<i<<" + "<<rest<<"\n";
                        break;
                    }
                }
            }
        }
    }

    return 0;
}