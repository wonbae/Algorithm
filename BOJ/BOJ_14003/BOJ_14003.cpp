#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define INF 1e9+4
typedef std::pair<int, int> pii;

using namespace std;

int n, num, cnt;
vector<pii> tmp;
vector<int> v(1000004, INF);
// stack<int> st;
vector<int> ans;

int main(){
    fastio;
    cin>>n;
    v.resize(n+4, INF);

    for(int i = 0; i < n; i++){
        cin>>num;
        
        auto it = lower_bound(v.begin(), v.begin()+cnt, num);
        int idx = (int)(lower_bound(v.begin(), v.begin()+cnt, num) - v.begin());
        if(*it == INF){
            cnt++;
        }
        *it = num;
    
        tmp.push_back({idx, num});
    }

    cout<<cnt<<"\n";
    
    reverse(tmp.begin(), tmp.end());

    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i].first == cnt - 1){
            ans.push_back(tmp[i].second);
            cnt -= 1;
        }
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    // for(int i = tmp.size()-1; i >= 0; i--){
    //     if(tmp[i].first == cnt-1){
    //         st.push(tmp[i].second);
    //         cnt--;
    //     }
    // }
    
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    return 0;
}
