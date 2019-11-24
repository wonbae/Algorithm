#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    
    while(true){

        getline(cin, str);
        if(str == ".")
            break;
        
        stack<char> st;
        bool flag = true;
        int len = str.length();

        for(int i = 0; i < len; i++){
            if(str[i] == '('){
                st.push('(');
            }
            else if(str[i] == '['){
                st.push('[');
            }
            else{
                if(str[i] == ')'){
                    if(st.empty()){
                        flag = false;
                        break;
                    }
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else if(str[i] == ']'){
                    if(st.empty()){
                        flag = false;
                        break;
                    }
                    if(st.top() == '['){
                        st.pop();
                    }else{
                        flag = false;
                        break;
                    }
                }else{
                    continue;
                }
            }
        }

        if(flag && st.empty()){
            cout<<"yes"<<"\n";
        }else{
            cout<<"no"<<"\n";
        }
    }
    

    return 0;
}