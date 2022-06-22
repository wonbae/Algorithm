#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int a, b, c, ans=0;
    cin>>a>>b>>c;
    vector<vector<int> > v(3, vector<int>(100,0));

    int start, end;
    for(int i = 0; i < 3; i++){
        cin>>start>>end;
        for(int j = start; j < end; j++){
            v[i][j] = 1;
        }
    }

    for(int i = 0; i < 100; i++){
        int tmp = v[0][i] + v[1][i] + v[2][i];
        if(tmp == 1) ans+=a;
        else if(tmp == 2){
            ans += (b*2);
        }else if(tmp == 3){
            ans += (c*3);
        }
    }

    cout<<ans<<"\n";

    return 0;
}