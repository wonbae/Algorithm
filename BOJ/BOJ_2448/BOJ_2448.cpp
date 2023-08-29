#include<bits/stdc++.h>
using namespace std;

char v[3072][6144];

void stars(int r, int c, int n){
    if(n == 3){
        v[r][c] = '*';
        v[r+1][c+1] = '*';
        v[r+1][c-1] = '*';
        for(int i = c - 2; i <= c + 2; i++){
            v[r+2][i] = '*';
        }
        return;
    }
    
    stars(r + n/2, c - n/2, n/2);
    stars(r + n/2, c + n/2, n/2);
    stars(r, c, n/2);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;

    memset(v, ' ', sizeof(v));

    stars(0, n-1, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n-1; j++){
            cout<<v[i][j];
        }
        cout<<"\n";
    }
}