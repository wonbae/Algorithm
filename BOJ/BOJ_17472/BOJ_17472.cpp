#include<iostream>
#include<queue>
using namespace std;

int map[11][11];
int visit[11][11];
int N,M;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct brg{
    int x;
    int y;
    int bcnt;
    brg(int a, int b, int c){
        x = a;
        y = b;
        bcnt = c;
    }
    bool operator<(const brg& w) const {
        return bcnt > w.bcnt;
    }
};

priority_queue<brg> pq;

void bridge(){
    bool flag = false;
    int cnt = 0, tmp;

    for(int i = 0; i < N; i++){
        flag = false;
        cnt = 0;

        for(int j = 0; j < M; j++){
            if(visit[i][j] != 0){
                if(flag){
                    if(visit[i][j] == tmp) continue;
                    if(visit[i][j] != tmp){
                        if(cnt > 1){
                            pq.push(brg(tmp, visit[i][j], cnt));
                        }else{
                            continue;
                        }
                    }
                }else{
                    flag = true;
                    tmp = visit[i][j];
                }
            }else{
                cnt++;
            }
            
        }
    }

    return ;
}

void bfs(){
    queue<pair<int, int> > q;
    int island = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                q.push(make_pair(i, j));
                visit[i][j] = 0;
                island++;

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nr = r + dr[idx];
                        int nc = c + dc[idx];

                        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                        if(visit[nr][nc]) continue;
                        if(map[nr][nc] == 0) continue;

                        if(map[nr][nc] == 1){
                            visit[nr][nc] = island;
                            q.push(make_pair(nr, nc));
                        }
                    }
                }
            }
        }
    }
    return ;
}

void solve(){
    bfs();
    bridge();
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>map[i][j];
        }
    }

    solve();

    return 0;
}