#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int t, h, w, n;
    cin>>t;
    while(t--){
        cin>>h>>w>>n;
        vector<vector<int> > v(h, vector<int>(w,0));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                v[i][j] = ((i+1)*100) + (j+1);
            }
        }
        
        int a, b;
        a = (n-1)%h;
        b = (n-1)/h;
        cout<<v[a][b]<<"\n";
    }
    return 0;
}