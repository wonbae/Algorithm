#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int t, n, len;
    string order;
    vector<int> v;

    cin>>t;

    while(t--){
        cin>>n;
        v.resize(n);    
        for(int i = 0; i < n; i++){
            cin>>v[i];
        }

        for(int i = 0; i < n; i++){
            int move=0;
            cin>>len>>order;
            for(int j = 0; j < order.size(); j++){
                if(order[j] == 'D'){
                    move++;
                }else{
                    move--;
                }
            }
            // cout<<"move: "<<move<<"\n";
            move%=10;
            // cout<<"move div: "<<move<<"\n";
            if(v[i] + move < 0){
                v[i] = 10+(v[i]+move);
            }else if(v[i] + move > 9){
                v[i] = (v[i] + move)%10;
            }else{
                v[i] += move;
            }
            // cout<<"v[i] : "<<v[i]<<"\n";
        }
        for(int i = 0; i < v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<"\n";

    }


    return 0;
}