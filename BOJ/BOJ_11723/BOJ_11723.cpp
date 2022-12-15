#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int m, x, s=0;
    string str;
    cin>>m;

    for(int i = 0; i < m; i++){
        cin>>str;
        if(str == "all"){
            s = (1<<21) - 1;
        }else if(str == "empty"){
            s = 0;
        }else if(str == "add"){
            cin>>x;
            s |= (1<<x);
        }else if(str == "check"){
            cin>>x;
            cout<<((s & (1<<x)) == 0 ? 0 : 1)<<"\n";
        }else if(str == "remove"){
            cin>>x;
            s &= ~(1<<x);
        }else if(str == "toggle"){
            cin>>x;
            s ^= (1<<x);
        }
    }
    return 0;
}