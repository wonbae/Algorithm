#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);

    ll n, k, mini = 2147000000, ans = -2147000000, count;
    cin>>n>>k;
    vector<ll> lan(n);

    for(int i = 0; i < n; i++){
        cin>>lan[i];
    }

    ll lt = 0, rt = 2147483647, mid;

    while(lt<=rt){
        count = 0;
        mid = (lt + rt) / 2;
        
        for(int i = 0; i < n; i++){
            count += lan[i] / mid;
        }

        if(count < k){
            rt = mid - 1;
        }else if(count >= k){
            ans = max(mid, int(ans));
            lt = mid + 1;
        }
    }

    cout<<ans<<"\n";
    return 0;
}