#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

// ll func(ll x){
//     ll y = 0, res = 0;

//     for(ll i = 1; x > 0; i *= 2){
//         if(x & 1){
//             y = x / 2 + 1;
//         }else{
//             y = x / 2;
//         }
        
//         res += (y * i);
        
//         x -= y;
//     }

//     return res;
// }

ll func(ll x){
    ll r = x;
    for(ll i = 2; i <= x; i *= 2){
        r += (x/i) * (i/2);
    }
    return r;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    ll a, b, cnt = 0, ans = 0;
    cin>>a>>b;

    cout<<(func(b) - func(a-1))<<"\n";

    return 0;
}