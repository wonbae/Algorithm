#include<bits/stdc++.h>
using namespace std;

#define LIM 10000000

int main(){
    int n;
    cin>>n;

    // vector<bool> isPrime(LIM + 1, true);

    // for(int i = 2; i <= LIM; i++){
    //     if(isPrime[i]){
    //         for(int j = 2*i; j<= LIM; j += i){
    //             if(isPrime[j]){
    //                 isPrime[j] = false;
    //             }
    //         }
    //     }
    // }

    int share = 0;

    while(true){

        if(n % 2 == 0){
            share = n / 2;
        }

    }




    return 0;
}