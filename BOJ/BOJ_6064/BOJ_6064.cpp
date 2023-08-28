#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int m, n, x, y;
        cin>>m>>n>>x>>y;

        bool flag = false;
        int k;

        for(k = x; k <= m*n; k+=m){
            if((k - 1) % n + 1 == y){
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<k<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }

    return 0;
}