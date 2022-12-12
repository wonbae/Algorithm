#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, num, cnt, res;
stack<pair<ll, ll> > st;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>num;
        
        cnt = 1;
        while(!st.empty() && st.top().first <= num){
            res += st.top().second;

            if(st.top().first == num){
                cnt = st.top().second + 1;
            }

            st.pop();
        }

        if(!st.empty()) res+=1;
        st.push({num, cnt});
    }

    cout<<res;

    return 0;
}