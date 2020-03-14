// boj_17135 Castle Defense G4
#include<bits/stdc++.h>
using namespace std;
#define SIZE 15

int N, M, D;
int Map[SIZE][SIZE];
int tmp[SIZE][SIZE];
bool visit[SIZE][SIZE];
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int enermy;

int dist(int nx, int ny, int x, int y){
    return abs(nx - x) + abs(ny - y);
}

void kill(){
    queue<pair<int, int> > q;
    int term = N;
    enermy = 0;

    while(term--){
        for(int c = 0; c < M; c++){
            if(Map[term + 1][c] == 2){
                memset(visit, false, sizeof(visit));
                memset(tmp, 0, sizeof(tmp));

                q.push(make_pair(term + 1, c));
                visit[term + 1][c] = true;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(visit[nx][ny]) continue;
                        if(tmp[nx][ny] > D) continue;

                        if(Map[nx][ny] == 1 && dist(nx, ny, term + 1, c) <= D){
                            enermy++;
                            
                        }
                        
                            tmp[nx][ny] += 1;
                            visit[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        
                        
                    }
                }
            }
        }
    }
}

void nCrArcher(int col, int cnt){
    if(cnt == 3){
        // for(int i = 0; i < M; i++){
        //     cout<<Map[N + 1][i]<<" ";
        // }
        // cout<<"\n";
        kill();
        return;
    }

    for(int i = 0; i < M; i++){
        if(Map[N + 1][i] == 2) continue;

        Map[N + 1][i] = 2;
        nCrArcher(col + 1, cnt + 1);
        Map[N + 1][i] = 0;
    }
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>D;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>Map[i][j]; 
        }
    }

    nCrArcher(0, 0);

    return 0;
}

