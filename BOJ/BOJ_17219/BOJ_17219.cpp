#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    map<string, string> mp;
    int n, m;
    string a, b;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        mp[a] = b;
    }

    string search;
    for(int i = 0; i < m; i++){
        cin>>search;
        cout<<mp[search]<<"\n";
    }
    return 0;
}