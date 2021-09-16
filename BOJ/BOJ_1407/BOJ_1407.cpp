#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

ll fn(ll num){
    ll n = num;
    for(ll i = 2; i <=num; i*=2){
        n +=(num/i)*(i/2);
        cout<<n<<",";
    }cout<<"\n";
    return n;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll a, b;

    cin>>a>>b;
    cout<<fn(b) - fn(a-1);
    return 0;
}