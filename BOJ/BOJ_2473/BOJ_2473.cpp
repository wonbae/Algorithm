#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;

ll mini = LLONG_MAX;

int main(){
    fastio;

    ll n;    

    cin>>n;
    vector<ll> v(n);
    vector<ll> ans(3);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    ll lpt , mpt, rpt;

    for(lpt = 0; lpt < n-2; lpt++){

        mpt = lpt + 1;
        rpt = n - 1;

        while(mpt < rpt){
            ll sumation = v[lpt] + v[mpt] + v[rpt];
            
            // cout<<v[lpt]<<", "<<v[mpt]<<", "<<v[rpt]<<"\n\n";

            if(abs(sumation) < mini){
                mini = abs(sumation);
                ans[0] = v[lpt];
                ans[1] = v[mpt];
                ans[2] = v[rpt];
            }

            if(sumation < 0) mpt++;
            else rpt--;
        }
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}