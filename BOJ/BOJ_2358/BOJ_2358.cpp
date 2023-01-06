#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    map<int, int> xm,ym;
    int n, x, y, ans=0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        xm[x]++;
        ym[y]++; 
    }

    for(auto a : xm){
        if(a.second >= 2) ans++;
    }
    for(auto b : ym){
        if(b.second >= 2) ans++;
    }

    cout<<ans;
    return 0;
}