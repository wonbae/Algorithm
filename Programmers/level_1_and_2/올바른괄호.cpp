#include<string>
// #include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    int len = s.length();
    
    for(int i = 0; i < len; i++){
        
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.empty()){
                answer = false;
                return answer;
            }
            else{
                st.pop();
            }
        }
    }
    if(st.empty()){
        answer = true;
    }else{
        answer = false;
    }
    
    return answer;
    
    //방법 2
    // int n = 0;
    // for (int i = 0; i < s.length(); i++) {
    //     if (n < 0)
    //         return false;
    //     if (s[i] == '(')
    //         n++;
    //     else if (s[i] == ')')
    //         n--;
    // }
    // return n == 0;
}
