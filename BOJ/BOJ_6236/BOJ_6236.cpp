#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL);
typedef long long ll;
using namespace std;

int n, m, k, num; 
ll res;
vector<int> v;

bool check(int a){
    k = a;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(k - v[i] >= 0){
            k -= v[i];
        }else{
            cnt++;
            k = a;
            if(v[i] > k) return 0;
            else k -= v[i];
        }
    }
    return cnt <= m;
}

int main(){
    fastio;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>num;
        v.push_back(num);
    }

    ll l = 1, r = 1000000004;
    while(l <= r){
        ll mid = l + ((r - l) / 2);
        if(check(mid)){
            r = mid - 1;
            res = mid;
        }else{
            l = mid + 1;
        }
    }
    cout<<res;
    return 0;
}