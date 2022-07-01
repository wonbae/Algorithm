#include<bits/stdc++.h>
using namespace std;

int v[101][101];
int h, w;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    cin>>h>>w;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char a;
            cin>>a;
            if(a=='c'){
                v[i][j] = 0;
            }else v[i][j] = -1;
        }
    }    

    for(int i = 0; i < h; i++){
        for(int j = 1; j < w; j++){
            if(v[i][j] == -1 && v[i][j-1] >= 0){
                v[i][j] = v[i][j-1] + 1;
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}