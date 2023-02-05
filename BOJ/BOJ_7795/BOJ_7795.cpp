#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL);
using namespace std;

int main(){
    fastio;
    int t, n, m, ans;
    
    cin>>t;

    for(int i = 0; i < t; i++){
        ans = 0;
        vector<int> a;
        vector<int> b;
        cin>>n>>m;
        for(int j = 0; j < n; j++){
            int num;
            cin>>num;
            a.push_back(num);
        }
        for(int j = 0; j < m; j++){
            int num;
            cin>>num;
            b.push_back(num);
        }

        sort(b.begin(), b.end());

        for(int j = 0; j < n; j++){
            int s = b.size();
            int pos = lower_bound(b.begin(), b.end(), a[j]) - b.begin();
            // cout<<a[j]<<", "<<pos<<", "<<b[pos]<<"\n";
            if(pos == b.size()) ans += pos;
            else if(a[j] >= b[pos]){
                ans += s - (s - pos);               
            }else if(a[j] < b[pos]){
                ans += s - (s - pos);
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}