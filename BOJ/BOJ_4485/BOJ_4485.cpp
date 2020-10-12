#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define INF 2147000000;

int map[126][126];
int dist[126][126];

int rdir[] = {-1, 0, 1, 0};
int cdir[] = {0, 1, 0, -1};
int n;

struct info{
    int row;
    int col;
    int val;
    info(int a, int b, int c){
        row = a;
        col = b;
        val = c;
    }
    bool operator<(const info& b)const{
        return val > b.val;
    }
};

void Dijkstra(){
    priority_queue<info> pq;

    pq.push(info(0, 0, map[0][0]));
    dist[0][0] = map[0][0];

    while(!pq.empty()){
        int r = pq.top().row;
        int c = pq.top().col;
        int num = pq.top().val;
        pq.pop();

        if(n - 1 == r && n - 1 == c) break;
        if(num != dist[r][c]) continue;

        for(int idx = 0; idx < 4; idx++){
            int nr = r + rdir[idx];
            int nc = c + cdir[idx];
            if(nr >= n || nr < 0 || nc >= n || nc < 0) continue;
            if(dist[nr][nc] > dist[r][c] + map[nr][nc]){
                dist[nr][nc] = dist[r][c] + map[nr][nc];
                pq.push(info(nr, nc, dist[nr][nc]));
            }
        }
    }
    
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int cnt = 0, ans = 0;

    while(1){
        cin>>n;
        cnt++;
        if(n == 0) break;

        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>map[i][j];    
                dist[i][j] = INF;        
            }
        }
        Dijkstra();
        ans = dist[n - 1][n - 1];
        cout<<"Problem "<<cnt<<": "<<ans<<"\n";
    }

    return 0;
}