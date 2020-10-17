#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 2147000000

int maze[101][101];
int dist[101][101];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int n, m;

struct info{
    int x;
    int y;
    int w;
    info(int a, int b, int c){
        x = a;
        y = b;
        w = c;
    }
    bool operator<(const info& we) const {
        return w > we.w;
    }
};

void bfs(){
    priority_queue<info> pq;
    pq.push(info(0, 0, 0));
    dist[0][0] = 0;

    while(!pq.empty()){
        int r = pq.top().x;
        int c = pq.top().y;
        int d = pq.top().w;
        pq.pop();

        if(d > dist[r][c]) continue;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nd = d + maze[nr][nc];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(dist[nr][nc] > nd){
                dist[nr][nc] = nd;
                pq.push(info(nr, nc, nd));
            }
        }   
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>maze[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist[i][j] = INF;
        }
    }

    bfs();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<dist[i][j]<<" ";
        }cout<<"\n";
    }
    

    return 0;
}