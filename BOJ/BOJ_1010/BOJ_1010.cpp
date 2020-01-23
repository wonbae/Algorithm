#include<bits/stdc++.h>
using namespace std;

int mem[31][31] = {0,};

int combination(int p, int q){

    if(p == q || q == 0) return 1;
    
    if(mem[p][q]) return mem[p][q];

    return mem[p][q] = combination(p - 1, q - 1) + combination(p - 1, q);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T,N,M;
    cin>>T;

    while(T--){
        memset(mem, 0, sizeof(mem));

        cin>>N>>M;

        cout<<combination(M,N)<<"\n";

    }

    return 0;
}