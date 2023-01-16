#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n, x, y;
    cin>>n;
    vector<pair<int, int> > v;
    while(n--){
        cin>>x>>y;
        v.push_back({y,x});   
    }
    sort(v.begin(), v.end());
    for(auto num : v){
        cout<<num.second<<" "<<num.first<<"\n";
    }
    return 0;
}