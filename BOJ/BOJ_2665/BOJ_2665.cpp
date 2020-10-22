#include<iostream>
#include<queue>
using namespace std;
#define INF 2147000000

int n, ans = 2147000000;
char map[51][51];
int inf [51][51];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
bool flag = false;

struct info{
    int x;
    int y;
    int w;
    info(int a, int b, int c){
        x = a;
        y = b;
        w = c;
    }
};

void bfs(){
    queue<info> q;
    q.push(info(0, 0, 0));
    inf[0][0] = 0;

    while(!q.empty()){
        int r = q.front().x;
        int c = q.front().y;
        int wall = q.front().w;
        q.pop();

        if(wall > inf[r][c]) continue;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

            if(map[nr][nc] == '1' && (inf[nr][nc] > inf[r][c])){
                inf[nr][nc] = inf[r][c];
                q.push(info(nr,nc,inf[r][c]));
            }

            else if(map[nr][nc] == '0' && (inf[nr][nc] > inf[r][c] + 1)){
                inf[nr][nc] = inf[r][c] + 1;
                q.push(info(nr, nc, inf[nr][nc]));
            }
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>map[i][j];
            inf[i][j] = INF;
        }
    }
    bfs();
    cout<<inf[n - 1][n - 1]<<"\n";
    return 0;
}