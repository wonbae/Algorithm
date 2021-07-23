#include<iostream>
#include<math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n,r,c, ans = 0, tmp;
    cin>>n>>r>>c;
    
    while(n){
        int index;
        tmp = pow(2, n) / 2;
        if(tmp > r && tmp > c) index = 0;           // 2사분
        else if(tmp > r && tmp <= c) index = 1;     // 1사분
        else if(tmp <= r && tmp > c) index = 2;     // 3사분
        else if(tmp <= r && tmp <= c) index = 3;    // 4사분

        r %= tmp;
        c %= tmp;

        ans += (tmp * tmp) * index;
        n--;
    }
    cout<<ans<<"\n";
    return 0;
}