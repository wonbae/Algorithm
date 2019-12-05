#include <bits/stdc++.h>
using namespace std;

#define limit 123456

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    vector<bool> isPrime(2 * limit, true);
    
    // isPrime[0] = false;  // 어짜피 i = 2부터 시작할꺼니깐 안해줘도됨
    // isPrime[1] = false;

    for(int i = 2; i*i <= 2 * limit; i++){
        if(isPrime[i]){
            // if(pow(i,2) > limit) {break;}
            for(int j = 2 * i; j <= 2 * limit; j += i){
                isPrime[j] = false;
            }
        }
    }

    while(1){
        cin>>N;
        int count = 0;

        if(N == 0) {break;}

        for(int i = N + 1; i <= 2*N; i++){
            if(isPrime[i]){
                // cout<<"prime : "<<i<<"\n";
                count++;
            }
        }

        cout<<count<<"\n";
    }

    return 0;
}