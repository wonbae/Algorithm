#include<iostream>
#include<stack>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    stack<char> st;
    string str;
    cin>>str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push('(');
        }else if(str[i] == ')'){
            if(st.empty()){
                cout<<"NO";
                return 0;
            }
            st.pop();
        }
    }

    if(st.empty()){
        cout<<"YES";
    }else cout<<"NO";


    return 0;
}