#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

bool cmp2(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int t, n;
    cin>>t;

    while(t--){
        cin>>n;

        vector<pair<ll,ll> > v, v2;

        v.resize(n+1);
        v2.resize(n+1);

        int num;
        for(int i = 1; i <= n; i++){
            cin>>num;
            v.push_back({i,num});
            v2.push_back({i,num});
        }

        sort(v.begin(), v.end(), cmp);//asc
        sort(v2.begin(), v2.end() ,cmp2);//desc

        int cnt = 0;

        for(int i = 0; i < v.size(); i++){
            if(v[i].first <= v[i].second) continue;
            
            for(int j = 0; j < v2.size(); j++){
                if(v[i].first >= v2[j].second) break;

                if(v[i].second < v[i].first && v[i].first < v2[j].second && v2[j].second < v2[j].first){
                    // cout<<v[i].second<<" < "<<v[i].first<<" < "<<v2[j].second<<" < "<<v2[j].first<<"\n";
                    cnt++;
                }    
            }
        }

        
        cout<<cnt<<"\n";
    }


    return 0;
}