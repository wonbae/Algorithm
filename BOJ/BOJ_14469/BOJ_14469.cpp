#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, ans = 0;
    vector<pair<int, int> > v;
    cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    int tmp = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first < tmp){
            tmp += v[i].second;
        }else{
            tmp = v[i].first + v[i].second;
        }
        
        ans = tmp;
    }

    cout<<ans;

    return 0;
}