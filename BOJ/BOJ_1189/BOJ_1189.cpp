#include<bits/stdc++.h>
using namespace std;

int r,c,k,ans;
int visited[6][6];
int load[6][6];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt){
    if(x == 1 && y == c){
        if(cnt == k){
            ans++;
            return ;
        }
        return ;
    }
    

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(visited[nx][ny] || nx < 1 || nx > r || ny < 1 || ny > c) continue;
        if(load[nx][ny] == 1) continue;

        visited[nx][ny] = 1;
        dfs(nx,ny,cnt+1);
        visited[nx][ny] = 0;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin>>r>>c>>k;
    string str;

    for(int i = 1; i <= r; i++){
        cin>>str;
        for(int j = 1; j <= str.size(); j++){
            if(str[j-1] == 'T'){
                load[i][j] = 1;
            }else{
                load[i][j] = 0;
            }
            
        }
    }

    visited[r][1] = 1;
    dfs(r,1,1);

    cout<<ans<<"\n";

    return 0;
}