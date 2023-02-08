#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL);
using namespace std;

bool check(int num, vector<int> &v){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = l + ((r - l) / 2);
        if(v[mid] > num) r = mid - 1;
        else if(v[mid] < num) l = mid + 1;
        else if(v[mid] == num) return true;
    }
    return false;
}

int main(){
    fastio;
    int t;
    cin>>t;

    while(t--){
        int n, num, m;
        cin>>n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        cin>>m;
        for(int i = 0; i < m; i++){
            cin>>num;
            if(check(num, v)){
                cout<<1<<"\n";
            }else cout<<0<<"\n";
        }

    }
    return 0;
}