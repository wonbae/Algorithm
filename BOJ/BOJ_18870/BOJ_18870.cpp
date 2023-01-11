#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n, num;
    map<int, int> mp;
    vector<int> v, v2;

    cin>>n; 

    for(int i = 0; i < n; i++){
        cin>>num;
        v.push_back(num);
    }
    v2 = v;

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(!mp[v[i]])
            mp[v[i]] = mp.size()-1;
    }

    for(int i = 0; i < n; i++){
        cout<<mp[v2[i]]<<" ";
    }
    return 0;
}