#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string n;

    while(cin>>n){
        bool flag = true;
        if((n[0] - 48) == 0) return 0;

        int len = n.length();
        for(int i = 0; i < len; i++){
            if(n[i] == n[len - 1 - i]) continue;
            else{
                cout<<"no"<<"\n";
                flag = false;
                break;
            }
        }
        if(flag) cout<<"yes"<<"\n";
    }

    return 0;
}