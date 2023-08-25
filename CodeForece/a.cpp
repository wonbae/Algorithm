#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int main(){
    fastio;

    string vika = "vika";
    int t;
    cin>>t;

    while(t--){
        int n, m;
        bool flag=false;

        cin>>n>>m;

        vector<string> str(n);

        for(int i = 0; i < n; i++){
            cin>>str[i];
        }    

        int idx = 0;
        for(int i = 0; i < m; i++){
            bool check = false;
            for(int j = 0; j < n; j++){
                if(vika[idx] == str[j][i]){
                    check = true;
                }
            }
            if(check){
                idx++;
                if(idx == 4){
                    break;
                }
            }
        }
        

        if(idx == 4){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}