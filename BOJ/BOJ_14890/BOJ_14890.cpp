#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int N, L, ans;
int load[101][101];
int load2[101][101];

void solve(int a[101][101]){
    for(int i = 0; i < N; i++){
        int cnt = 1;
        int j;
        for(j = 0; j < N-1; j++){
            if(a[i][j] == a[i][j+1]) cnt++;
            else if(a[i][j] + 1 == a[i][j+1] && cnt>=L) cnt = 1; //오르막길 
            else if(a[i][j] - 1 == a[i][j+1] && cnt>=0) cnt = -L+1; //내리막길
            else break;   
        }

        if(cnt >= 0 && j == N-1) ans++;
    }
    return ;
}

int main(){
    FASTIO
    cin>>N>>L;
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            cin>>load[i][j];
            load2[j][i] = load[i][j]; 
        }
    }

    solve(load);
    solve(load2);
    cout<<ans<<"\n";
    return 0;
}