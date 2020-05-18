#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, K, lt = 1, rt = 2147483647, mid, tmp = 0;
    int res = 0;

    cin>>N>>K;
    vector<ll> v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i];
    }

    while(lt <= rt){
        tmp = 0;
        mid = (lt + rt) / 2;

        for(int i = 0; i < N; i++){
            tmp += v[i] / mid;
        }

        if(tmp >= K){
            res = max(mid, int(res));
            lt = mid + 1;
        }
        else if(tmp < K){
            rt = mid - 1;
        }
    }
    cout<<res<<"\n";
    return 0;
}