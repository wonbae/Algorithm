#include<iostream>
using namespace std;

int map[7][7], ch[7][7], cnt;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c){
    if(r == 6 && c == 6){
        cnt++;
    }else{
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 7 || nc >= 7 || nr < 0 || nc < 0) continue;
            else{
                if(map[nr][nc] == 0 && ch[nr][nc] == 0){
                    ch[nr][nc] = 1;
                    dfs(nr, nc);
                    ch[nr][nc] = 0;
                }
            }
        }
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            cin>>map[i][j];
        }
    }

    ch[0][0] = 1;
    dfs(0, 0);
    cout<<cnt<<"\n";
    return 0;
}