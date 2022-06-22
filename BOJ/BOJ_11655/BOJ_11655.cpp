#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string str, ans="";
    getline(cin,str);
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            int idx = str[i]-'a';
            char tmp = ('a' + (idx+13)%26);
            ans += tmp;
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            int idx = str[i]-'A';
            char tmp = ('A' + (idx+13)%26);
            ans += tmp;
        }else{
            ans+=str[i];
        }
    }

    cout<<ans;
    return 0;
}