#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
typedef long long ll;
#define MAX 60000000004;
using namespace std;

ll n, m, res;
vector<ll> v;
ll lt = 0, rt = MAX;

bool check(ll mid){
    ll tmp = m;
    for(int i = 0; i < m; i++) tmp += mid/v[i];
    return tmp >= n;
}

int main(){
    fastio;
    cin>>n>>m;
    v.resize(m);
    for(int i = 0; i < m; i++){
        cin>>v[i];
    }

    if(n <= m){
        cout<<n;
        return 0;
    }

    while(lt <= rt){
        ll mid = lt + ((rt - lt) / 2);
        if(check(mid)){
            res = mid;
            rt = mid - 1;
        }else lt = mid + 1;
    }

    ll temp = m;
    for(int i = 0; i < m; i++) temp += (res - 1) / v[i];

    for(int i = 0; i < m; i++){
        if(res % v[i] == 0) temp++;
        if(temp == n){
            cout<<i + 1<<"\n";
            return 0;
        }
    }
    return 0;
}