#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, k, cnt = 0;
    cin>>n>>k;

    vector<bool> isPrime(n+1, true);
    
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            for(int j = i; j <= n; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    cnt++;

                    if(cnt == k){
                        cout<<j<<"\n";
                        return 0;
                    }
                }else continue;
            }
        }
    }

    return 0;
}