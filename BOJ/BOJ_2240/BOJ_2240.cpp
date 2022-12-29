#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int a[1001][2][31];
int b[1001];
int t,w;

int solve(int idx, int tree, int cnt){
    //base condi
    if(idx == t) return 0;
    if(cnt < 0) return 0;

    //memo
    int tmp = a[idx][tree][cnt];
    if(tmp != -1) return tmp;

    //logic
    return a[idx][tree][cnt] = max(solve(idx+1, tree == 1?0:1, cnt-1), solve(idx+1, tree, cnt)) + (tree == b[idx]-1);
}

int main(){
    fastio;
    
    memset(a, -1, sizeof(a));
    cin>>t>>w;
    for(int i = 0; i < t; i++){
        cin>>b[i];
    }    

    cout<<max(solve(0, 1, w-1), solve(0, 0, w))<<"\n";
    return 0;
}