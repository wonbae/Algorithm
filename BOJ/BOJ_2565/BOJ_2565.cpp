#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int lis[504];

int main(){
    fastio;
    int n, a, b, tmp = 0;
    vector<pair<int, int> > v;
        
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        auto it = lower_bound(lis, lis + tmp, v[i].second);
        if(*it == 0) tmp++;
        *it = v[i].second;
    }

    cout<<n - tmp;
    return 0;
}