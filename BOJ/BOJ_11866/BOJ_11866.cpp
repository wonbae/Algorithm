#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    int n, k;
    cin>>n>>k;

    vector<int> v;
    vector<int> ans;

    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }

    int idx = 0;
    while(!v.empty()){
        idx = (idx + (k-1))%v.size();
        ans.push_back(v[idx]);
        v.erase(v.begin()+idx);
    }

    cout<<"<";
    for(int i = 0; i < ans.size(); i++){
        if(i==ans.size()-1){
            cout<<ans[i];
        }else{
            cout<<ans[i]<<", ";
        }
    }
    cout<<">";

    return 0;
}