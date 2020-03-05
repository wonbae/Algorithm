#include<bits/stdc++.h>
using namespace std;

#define MAX 8

int Map[MAX][MAX];
int tmp[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
queue<pair<int, int> > virus;
int safe;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int virus_cnt;
int answer = 987654321;

void bfs(){
    memset(visit, false, sizeof(visit));
    virus_cnt = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            tmp[i][j] = Map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tmp[i][j] == 2) virus.push(make_pair(i, j)), visit[i][j] = true;

            while(!virus.empty()){
                int x = virus.front().first;
                int y = virus.front().second;
                virus.pop();
                visit[x][y] = true;

                for(int idx = 0; idx < 4; idx++){
                    int nx = x + dx[idx];
                    int ny = y + dy[idx];

                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if(visit[nx][ny] || tmp[nx][ny] != 0) continue;

                    if(tmp[nx][ny] == 0){
                        visit[nx][ny] = true;
                        tmp[nx][ny] = 2;
                        virus.push(make_pair(nx, ny));
                        virus_cnt++;
                    }
                }
            }
        }
    }

    // safe = 0;
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         // if(tmp[i][j] == 2) cnt++;   //count virus
    //         if(tmp[i][j] == 0) safe++;
    //     }
    // }
    
    answer = min(answer, virus_cnt);

}

void dfs(int x, int y, int wall){
    if(wall == 3){
        bfs();
        return;
    }

    for(int i = x; i < N; i++){
        int k = i == x ? y : 0;
        for(int j = k; j < M; j++){
            if(Map[i][j] == 0){
                Map[i][j] = 1;
                dfs(i, j, wall + 1);
                Map[i][j] = 0;
             
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>Map[i][j];
            if(Map[i][j] == 0) safe++;
        }
    }

    dfs(0, 0, 0);

    cout<<safe - answer - 3<<"\n";

    return 0;
}