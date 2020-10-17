#include<bits/stdc++.h>
using namespace std;

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

char Map[1001][1001];
int visit[1001][1001][2];
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int n, m, ans;
bool flag = false;

void bfs(){
    queue<info> q;
    q.push(info(0, 0, 0));
    visit[0][0][0] = 1;

    while(!q.empty()){
        int r = q.front().x;
        int c = q.front().y;
        int wall = q.front().w;
        q.pop();

        if(r == n - 1 && c == m - 1){
            ans = visit[r][c][wall];
            flag = true;
            return ;
        } 
        for(int idx = 0; idx < 4; idx++){
            int nr = r + dr[idx];
            int nc = c + dc[idx];

            if(nr < 0 || nr >= n  || nc < 0 || nc >= m) continue;
            if(visit[nr][nc][wall]) continue;

            if(Map[nr][nc] == '0'){
                visit[nr][nc][wall] = visit[r][c][wall] + 1;
                q.push(info(nr,nc,wall));
            }

            if(Map[nr][nc] == '1' && wall == 0){
                visit[nr][nc][1] = visit[r][c][wall] + 1;
                q.push(info(nr,nc,1));
            }
            
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>Map[i][j];
        }
    }
    bfs();
    if(flag) cout<<ans<<"\n";
    else cout<<-1<<"\n";
    
    return 0;
}