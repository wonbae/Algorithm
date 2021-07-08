#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 8

int Map[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
queue<pair<int, int> > virus;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int answer = 2147000000;

void bfs(){
    memset(visit, false, sizeof(visit));
    int virus_cnt = 0;
    int tmp[MAX][MAX];

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
            // cout<<"i: "<<i<<", "<<"k:"<<k<<", "<<"j:"<<j<<"\n";
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
    cin.tie(NULL);

    int safe = 0;

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