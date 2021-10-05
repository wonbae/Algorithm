#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, cnt = 0, ans = 0;
    cin>>n;
    stack<int> st;
    vector<int> vec(n);
    string str;
    cin>>str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push(i);
        }else{
            if(!st.empty()){
                vec[i] = vec[st.top()] = 1;
                st.pop();
            }
        }
    }

    for(int i = 0; i < vec.size(); i++){
        if(vec[i]){
            cnt++;
            ans = max(ans, cnt);
        }
        else{
            cnt = 0;
        }
    }
    
    cout<<ans;
    return 0;
}