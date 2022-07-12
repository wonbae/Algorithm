#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){    
        string str,tmp="";
        cin>>str;
        for(int i = 0; i < str.size(); i++){
            if('A'<=str[i] && str[i] <= 'Z'){
                tmp+=str[i]+32;
            }else{
                tmp+=str[i];
            }
        }        
        if(tmp == "yes"){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }


    return 0;
}