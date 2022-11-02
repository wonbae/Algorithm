#include<bits/stdc++.h>
using namespace std;

int bord[21][21];
bool check[26]={false,};
int R, C, cnt = 0, ans = 0;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int r, int c, int cnt){
    ans = max(cnt, ans);

    for(int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        int next = bord[nr][nc];
        if(check[next] == 0){
            check[next] = 1;
            dfs(nr,nc,cnt+1);
            check[next] = 0; 
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    cin>>R>>C;
    string str;

    for(int i = 0; i < R; i++){
        cin>>str;
        for(int j = 0; j < str.size(); j++){
            bord[i][j] = str[j]-'A';
        }
    }

    check[bord[0][0]]=true;
    dfs(0,0,1);
    
    cout<<ans<<"\n";

    return 0;
}