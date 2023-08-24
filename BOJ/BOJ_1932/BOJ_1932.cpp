#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int> > v(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin>>v[i][j];
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= i+1; j++){
            v[i][j] += max(v[i+1][j], v[i+1][j+1]);
        }
    }
    
    cout<<v[0][0];

    return 0;
}