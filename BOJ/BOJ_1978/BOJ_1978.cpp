#include <bits/stdc++.h>
using namespace std;

bool prime(int p){
    if(p == 1) return false;

    for(int i = 2; i * i <= p; i++){
        if(p % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int T;
    cin>>T;

    int p;
    int count = 0;

    for(int i = 0; i < T; i++){
        cin>>p;
        if(prime(p)){
            count++;
        }
    }

    cout<<count<<"\n";


    return 0;
}