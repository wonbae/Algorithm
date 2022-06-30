#include<bits/stdc++.h>
using namespace std;

int check[101][101], v[101][101], sink[101][101], N, cnt, ans=1;
const int idx[] = {0, 1, 0, -1};
const int idy[] = {1, 0, -1, 0};

void dfs(int x, int y){
    check[x][y] = 1;
    
    for(int i = 0; i < 4; i++){
        int nx = x + idx[i];
        int ny = y + idy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(!check[nx][ny] && sink[nx][ny] == 0) dfs(nx,ny);
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>v[i][j];
        }
    }

    for(int h = 1; h <= 100; h++){
        cnt=0;
        fill(&check[0][0], &check[0][0] + 101*101, 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(v[i][j] <= h){
                    sink[i][j] = 1;
                }else{
                    sink[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(check[i][j] == 0 && sink[i][j] == 0){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        ans = max(cnt,ans);
    }
    cout<<ans<<"\n";

    return 0;
}