#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n,l,s,e,ans=0;
    vector<pair<int, int> > v;
    cin>>n>>l;
    for(int i = 0; i < n; i++){
        cin>>s>>e;
        v.push_back({s,e});
    }

    sort(v.begin(), v.end());

   int idx = 0, tmp = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i].second <= idx) continue;
        if(idx < v[i].first){
            tmp = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
            idx = v[i].first + tmp * l;
        }else{
            tmp = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0);
            idx = idx + tmp * l;
        }

        ans+=tmp;
    }
    
    cout<<ans<<"\n";
    return 0;
}
// Point of No Return