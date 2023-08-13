#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

// bool customoper(const pair<int, int>& a, const int& b){
//     return a.second <= b;
// }

int main(){
    fastio;
    int n, a, b, tmp = 0;
    vector<pair<int, int> > v;
    vector<int> lis;
    vector<int> index;
    vector<int> del;
        
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    lis.push_back(v[0].second);
    index.push_back(0);

    for(int i = 1; i < n; i++){
        int cur = v[i].second;

        if(lis.back() < cur){
            index.push_back(lis.size());
            lis.push_back(cur);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), cur);
            int idx = it-lis.begin();
            *it = cur;
            index.push_back(idx);
        }
    }

    cout<<n-lis.size()<<"\n";

    // for(int i = 0; i < lis.size(); i++){
    //     cout<<lis[i]<<" ";
    // }cout<<"\n";

    // for(int i = 0; i < index.size(); i++){
    //     cout<<index[i]<<" ";
    // }cout<<"\n";

    int pos = lis.size() - 1;

    for(int i = index.size() - 1; i >= 0; i--){
        if(index[i] == pos){
            pos--;
        }else{
            del.push_back(v[i].first);
        }
    }

    for(int i = del.size() - 1; i >= 0; i--){
        cout<<del[i]<<"\n";
    }
}