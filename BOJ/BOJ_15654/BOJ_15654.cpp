#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<int> ans;
int check[8];

void solve(int cnt){
    if(cnt == m){
        for(auto num : ans){
            cout<<num<<" ";
        }cout<<"\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(check[i]) continue;
        ans.push_back(v[i]);
        check[i] = true;

        solve(cnt+1);

        ans.pop_back();
        check[i] = false;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    cin>>n>>m;
    
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    solve(0);
    return 0;
}