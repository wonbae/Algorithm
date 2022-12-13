#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    stack<int> st;
    string str;
    int n, cnt=0,ans=0;
    cin>>n;
    vector<int> v(n,0);
    cin>>str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            st.push(i);
        }else{
            if(!st.empty()){
                v[i] = v[st.top()] = 1;
                st.pop();
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        if(v[i]){
            cnt++;
            ans = max(cnt, ans);
        }else cnt = 0;
    }

    cout<<ans<<"\n";
    return 0;
}