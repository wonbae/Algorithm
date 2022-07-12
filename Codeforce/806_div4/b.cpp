#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int t, n;
    string str;
    
    cin>>t;

    while(t--){
        int ans = 0;
        bool check[26];
        memset(check, true, sizeof(check));
        cin>>n>>str;

        for(int i = 0; i < n; i++){
            if(check[str[i]-'A']){
                ans+=2;
                check[str[i]-'A'] = false;
            }else{
                ans+=1;
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}