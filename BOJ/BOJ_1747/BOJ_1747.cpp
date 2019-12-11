#include<bits/stdc++.h>
using namespace std;

#define LIM 1004000

bool palindrome(int num){
    string tmp = to_string(num);
    int len = tmp.length();
    int end_idx = len - 1;

    for(int i = 0; i < len/2; i++){
        if(tmp[i] == tmp[end_idx - i]){
            continue;
        }else{
            return false;
        }
    }

    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin>>N;

   vector<bool> isPrime(LIM + 1, true);
   vector<int> prime;

   isPrime[0] = false;
   isPrime[1] = false;

   for(int i = 2; i <= LIM; i++){
       if(isPrime[i]){
           if(N <= i){
               prime.push_back(i);
           }
           for(int j = i * 2; j <= LIM; j += i){
               if(isPrime[j]){
                   isPrime[j] = false;
               }
           }
       }
   }

   for(int i = 0; i < prime.size(); i++){
       if(palindrome(prime[i])){
           cout<<prime[i]<<"\n";
           return 0;
       }
   }



    return 0;
}