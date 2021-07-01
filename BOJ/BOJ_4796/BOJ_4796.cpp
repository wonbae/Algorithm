#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int tc = 1, p, l, v, ans = 0;

    while(true){
        cin>>l>>p>>v;

        if(l == 0 && p == 0 && v == 0) break;

        int tmp = v / p;
        int tmp2 = 0;
        int rest = v % p;

        if(rest > l){
            tmp2 = l;
        }else{
            tmp2 = rest;
        }
        ans = (tmp * l)+ tmp2;

        cout<<"Case "<<tc<<": "<<ans<<"\n";
        tc++;
    }
    return 0;
}