#include<bits/stdc++.h>
using namespace std;

int a[26];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    string str, ans="";

    cin>>n;
    while(n--){
        cin>>str;
        a[str[0]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(a[i] >= 5){
            ans+=('a'+i);
        }
    }

    if(ans.empty()){
        cout<<"PREDAJA";
    }else{
        cout<<ans;
    }

    return 0;
}