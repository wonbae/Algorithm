#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> v(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][k] && v[k][j]){
                    v[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}