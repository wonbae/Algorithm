#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    string str;
    stack<char> st;

    cin>>str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push('(');
        }else{
            st.pop();
            if(str[i - 1] == '(') sum += st.size();
            else sum += 1;
        }
    }

    cout<<sum<<"\n";

    return 0;
}