#include<bits/stdc++.h>
using namespace std;

int gcd(int p, int q){
    if(q == 0) return p;
    return gcd(q, p%q);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b;

    cin>>a>>b;

    int res = gcd(a,b);
    cout<<res<<"\n";
    cout<<res * (a / res) * (b / res)<<"\n";

    return 0;
}