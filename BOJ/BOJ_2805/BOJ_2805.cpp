#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, mid, lt = 0, rt = -2147000000, sum, ans;
    cin>>n>>m;
    vector<ll> v(n);

    for(ll i = 0; i < n; i++){
        cin>>v[i];
        if(rt < v[i]) rt = v[i];
    }

    while(lt <= rt){
        mid = (lt + rt) / 2;
        sum = 0;

        for(ll i = 0; i < n; i++){
            if(mid < v[i]){
                sum += v[i] - mid;
            }
        }

        if(sum == m){
            ans = mid;
            lt = lt + 1;    //break; 해줘도됨
        }else if(sum < m){
            rt = mid - 1;
        }else if(sum > m){
            ans = mid;  //sum == m이 안될경우 차선책임
            lt = mid + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}