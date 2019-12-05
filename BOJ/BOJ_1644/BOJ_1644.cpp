#include<bits/stdc++.h>
using namespace std;

#define LIMIT 4000000

int main(){
    vector<bool> isPrime(LIMIT + 1, true);
    

    for(int i = 2; i*i <= LIMIT; i++){
        if(isPrime[i]){
            for(int j = (i*2); j <= LIMIT; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                }
            }
        }
    }
    isPrime[0] = false;
    isPrime[1] = false;

    
    int n;
    vector<int> prime;

    cin>>n;

    // prime.resize(n + 1, 0);

    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }

    int count = 0;
    int left = 0, right = 0, sum = 0;

    while(true){
        
        if(sum >= n){
            sum -= prime[left++];
        }else if(right == prime.size()){
            break;
        }else{
            //sum < n
            sum += prime[right++];
        }

        if(sum == n) { count++; }

    }

    cout<<count<<"\n";


    return 0;
}



// queue<int> q;
// 	for(int i = 2, sum = 0; i <= n; ++i) {
// 		if(prime[i]) {
// 			q.push(i);
// 			sum += i;
// 			if(sum == n) {
// 				++res;
// 			} else if(sum > n) {
// 				while(sum > n) {
// 					sum -= q.front();
// 					q.pop();
// 				}
// 				if(sum == n) ++res;
// 			}
// 		}
// 	}