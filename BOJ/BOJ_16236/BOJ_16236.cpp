#include<bits/stdc++.h>
using namespace std;
#define SIZE 20

typedef pair<int, pair<int, int> > pdxy;

int Map[SIZE][SIZE];
bool visit[SIZE][SIZE];
int N, r, c, TIME;
int sharkSize, eat;

void babySharck(){
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    priority_queue<pdxy, vector<pdxy>, greater<pdxy> > pq;

    pq.push(make_pair(0, make_pair(r, c)));
    visit[r][c] = true;
    Map[r][c] = 0;

    while(!pq.empty()){
        
        int dist = pq.top().first;
        int x = pq.top().second.first, y = pq.top().second.second;
        // cout<<"dist : "<<dist<<", x : "<<x<<", y : "<<y<<"\n";
        pq.pop();

        if(Map[x][y] < sharkSize && Map[x][y] > 0){
            Map[x][y] = 0;
            eat++;

            if(sharkSize == eat){
                eat = 0;
                sharkSize++;
            }

            TIME += dist;
            
            dist = 0;

            memset(visit, false, sizeof(visit));
            while(!pq.empty()){
                pq.pop();
            }
        }

        for(int idx = 0; idx < 4; idx++){
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visit[nx][ny] == true) continue;
            if(Map[nx][ny] > 0 && Map[nx][ny] > sharkSize) continue;

            pq.push(make_pair(dist + 1, make_pair(nx, ny)));
            visit[nx][ny] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>Map[i][j];
            if(Map[i][j] == 9) r = i, c = j;
        }
    }

    sharkSize = 2;
    babySharck();

    cout<<TIME<<"\n";

    return 0;
}