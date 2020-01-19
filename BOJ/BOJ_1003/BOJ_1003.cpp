#include<bits/stdc++.h>
using namespace std;

int memo[41] = {1,1,};

int fibo(int n){
    if(n <= 1){
        return memo[n];
    }else{
        if(memo[n] != 0){
            return memo[n];
        }
    }
    
    return memo[n] = fibo(n - 1) + fibo(n - 2);

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T,N;

    cin>>T;

    while(T--){
        cin>>N;
        if(N == 0) cout<<1<<" "<<0<<"\n";
        else if(N == 1) cout<<0<<" "<<1<<"\n";
        else{
            fibo(N);
            cout<<memo[N-2]<<" "<<memo[N-1]<<"\n";
        }
        
    }

    return 0;
}