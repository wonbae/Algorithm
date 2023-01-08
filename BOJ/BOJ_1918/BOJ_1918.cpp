#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(){
    fastio;
    stack<char> st;
    string str, ans="";
    cin>>str;

    for(int i = 0; i < str.size(); i++){
        if(65 <= str[i] && str[i] <= 90){
            ans+=str[i];
        }else{
            if(str[i] == '-' || str[i] == '+'){
                while(!st.empty() && (st.top() != '(')){
                    ans+=st.top();
                    st.pop();
                }
                st.push(str[i]);
            }else if(str[i] == '('){
                st.push(str[i]);
            }else if(str[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }else if(str[i] == '*' || str[i] == '/'){
                while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                    ans+=st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    cout<<ans<<"\n";

    return 0;
}