#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, m;
    int matrix[20][20] = {0,};
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int r, c, val;
        cin>>r>>c>>val;
        matrix[r - 1][c - 1] = val;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}