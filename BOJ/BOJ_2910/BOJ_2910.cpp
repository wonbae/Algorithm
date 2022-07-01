#include<bits/stdc++.h>
using namespace std;

map<int,int> m, prio;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return prio[a.first] < prio[b.first];
    }
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, c, a;
    cin>>n>>c;
    
    vector<pair<int,int> > v;
    for(int i = 0; i < n; i++){
        cin>>a;
        m[a]+=1;
        if(prio[a] == 0) prio[a] = i+1;
    }

    for(auto num : m){
        v.push_back({num.first, num.second});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto num : v){
        for(int i = 0; i < num.second; i++){
            cout<<num.first<<" ";
        }
    }

    return 0;
}