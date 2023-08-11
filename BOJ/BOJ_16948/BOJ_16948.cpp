#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);


int main(){
    fastio;

    int n, l, r, x, res = 0;
    vector<int> v;

    cin>>n>>l>>r>>x;
    v.resize(n);
    
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    for(int i = 1; i < (1<<n); i++){
        int maxi = 0, mini = 2147000000, sum = 0, cnt = 0;
        for(int j = 0; j < n; j++){
            // cout<<"i : "<<i<<", j : "<<j<<" = "<<(i & (1<<j))<<"\n";
            if(i & (1<<j)){
                maxi = max(maxi, v[j]);
                mini = min(mini, v[j]);
                sum += v[j];
                cnt++;
            }
        }

        if(cnt >= 2 && l <= sum && sum <= r && maxi - mini >= x){
            res++;
        }
    }

    cout<<res;
    
    return 0;
}