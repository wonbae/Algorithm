#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3;
    
    
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                cout<<i<<", "<<j<<"\n";
                // cout<<(1<<j)<<"\n";
                // cout<<(i & (1<<j))<<"\n";
            }
        }cout<<"\n";
    }


    return 0;
}