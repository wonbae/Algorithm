#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
ll mini = LLONG_MAX;

int main(){
    fastio;
    
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> ans(2);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int lt = 0, rt = n - 1;

    while(lt < rt){
        ll sumation = v[lt] + v[rt];

        if(abs(sumation) < mini){
            mini = abs(sumation);
            ans[0] = v[lt];
            ans[1] = v[rt];
        }

        if(sumation < 0) lt++;
        else rt--;
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}