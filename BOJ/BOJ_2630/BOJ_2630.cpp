#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int white=0, blue=0;
int arr[129][129];
int n;

void solve(int s, int e, int l){
    //base condi
    if(l == 1){
        if(arr[s][e] == 1) blue++;
        else white++;
        return;
    }

    bool wflag = true, bflag = true;
    for(int i = s; i < s+l; i++){
        for(int j = e; j < e+l; j++){
            if(arr[i][j]){
                wflag=false;
            }else{
                bflag=false;
            }
        }
    }

    if(bflag){
        blue++;
        return;
    } 
    else if(wflag){
        white++;
        return;
    } 
    else{
        solve(s, e, l/2);
        solve(s, e+l/2, l/2);
        solve(s+l/2, e, l/2);
        solve(s+l/2, e+l/2, l/2);
    }
    return ;
}

int main(){
    fastio;
    
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    solve(0, 0, n);

    cout<<white<<"\n"<<blue<<"\n";

    return 0;
}