#include<iostream>
typedef unsigned long long ull;
using namespace std;

ull a,b,c;

ull multi(ull a, ull b){
    ull sum = 0;
    while(a>0){
        if(a&1){
            sum+=b;
            sum%=c;
        }
        a>>=1;
        b<<=1;
        a%=c;
        b%=c;
    }
    return sum%c;
}

ull pow(ull base, ull exp){ 
    if (base == 1) 
        return 1; 
    ull ans = 1; 
    while (exp) { 
        if (exp & 1) { 
            // if exp is odd 
            ans = multi(ans, base); 
            // ans = (ans * base);
            ans%=c;
        } 
        base=multi(base, base);
        base%=c;
        exp>>=1; 
        exp%=c;
    } 
    return ans%c; 
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>a>>b>>c;
    cout<<pow(a,b)%c<<"\n";
    return 0;
}