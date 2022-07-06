#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int t;
    cin>>t;
    string str;

    while(t--){
        stack<char> s;
        bool flag = false;
        cin>>str;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '('){
                s.push('(');
            }else{
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }else if(s.empty()){
                    cout<<"NO\n";
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            if(s.empty()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}