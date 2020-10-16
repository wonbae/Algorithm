#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int Map[201][201];
int vist[201][201][31];
int k, w, h;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int hx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int hy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void bfs(){
    memset(vist, -1, sizeof(vist));
    queue<pair<pair<int, int> , int> > q;
    q.push(make_pair(make_pair(0, 0), 0));
    vist[0][0][0] = 0;

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cost = q.front().second;
        q.pop();

        if(cost < k){
            for(int idx = 0; idx < 8; idx++){
                int nr = r + hx[idx];
                int nc = c + hy[idx];
                int ncost = cost + 1;

                if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                if(Map[nr][nc] != 1 && vist[nr][nc][ncost] == -1){
                    q.push(make_pair(make_pair(nr,nc), ncost));
                    vist[nr][nc][ncost] = vist[r][c][cost] + 1;
                }
            }    
        }

        for(int idx = 0; idx < 4; idx++){
            int nr = r + dx[idx];
            int nc = c + dy[idx];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if(Map[nr][nc] != 1 && vist[nr][nc][cost] == -1){
                q.push(make_pair(make_pair(nr,nc), cost));
                vist[nr][nc][cost] = vist[r][c][cost] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mini = 2147000000;
    cin>>k>>w>>h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin>>Map[i][j];
        }
    }

    bfs();

    for(int i = 0; i <= k; i++){
        if(vist[h - 1][w - 1][i] != -1 && vist[h - 1][w - 1][i] < mini){
            mini = vist[h-1][w-1][i];
        }
    }

    if(mini == 2147000000) cout<<-1<<"\n";
    else cout<<mini<<"\n";

    return 0;
}