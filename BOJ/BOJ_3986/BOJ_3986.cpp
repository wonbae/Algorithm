#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int tc, ans=0;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;

        stack<char> st;

        for(int i = 0; i < str.size(); i++){
            if(st.empty()){
                st.push(str[i]);
            }else{
                if(st.top() == str[i]) st.pop();
                else st.push(str[i]);
            }
        }
        
        if(st.empty()) ans++;
    }

    cout<<ans;
    return 0;
}