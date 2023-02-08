#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n, m, cnt = 0, num;
    cin>>n>>m;
    map<int, int> mp;

    for(int i = 0; i < n; i++){   
        cin>>num;
        mp[num]++;
    }
    for(int i = 0; i < m; i++){
        cin>>num;
        mp[num]++;   
    }
    
    for(auto it : mp){
        if(it.second == 1) cnt++;
    }
    cout<<cnt;
    return 0;
}