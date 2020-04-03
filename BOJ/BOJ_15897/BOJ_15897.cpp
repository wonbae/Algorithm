#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, ans = 0;
    cin>>n;

    n -= 1;

	for (int i = n + 1; i != 0; i = n / ((n / i) + 1))
		ans += (n / i + 1) * (i - (n / ((n / i) + 1)));

	cout<<ans<<"\n";
}


// ll i = 1, n;

// ll failEratos(ll icnt){
//     ll tmp, next;

//     tmp = (n - 1) / icnt;

//     if(tmp == 0) next = n;
//     else{
//         next = (n - 1) / tmp;
//     }
    
//     i = next;
//     ll res = (tmp + 1) * (next - icnt + 1);

//     return res;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     ll ans = 0;   

//     cin>>n;

//     ans += n;
//     while(i < n){
//         ans += failEratos(i + 1);
//     }
    
//     cout<<ans<<"\n";

//     return 0;
// }