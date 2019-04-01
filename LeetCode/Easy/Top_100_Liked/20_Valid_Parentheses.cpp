class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int ch : s){
            if(ch == '[' || ch == '(' || ch == '{'){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }
                if(ch == ']' && st.top() != '['){
                    return false;
                }
                if(ch == ')' && st.top() != '('){
                    return false;
                }
                if(ch == '}' && st.top() != '{'){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty() ? true : false;
    }
};
