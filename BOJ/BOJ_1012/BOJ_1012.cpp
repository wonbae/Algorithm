#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int M,N,K;  //M 가로, N 세로
int Map[MAX][MAX] = {0,};
int Visit[MAX][MAX] = {0,};

void PRINT(){
    cout<<"\n==== MAP =====\n";
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cout<<Map[y][x];
        }cout<<"\n";
    }
}

void PRINT_VISIT(){
    cout<<"\n==== VISIT =====\n";
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cout<<Visit[y][x];
        }cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    queue<pair<int, int> > q;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    cin>>T;

    while(T--){
        cin>>M>>N>>K;

        memset(Map, 0, sizeof(Map));
        memset(Visit, 0, sizeof(Visit));

        int X,Y;
        for(int i = 0; i < K; i++){
            cin>>X>>Y;
            Map[Y][X] = 1;
        }

        // PRINT();

        int cnt = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Visit[i][j] == 0 && Map[i][j] == 1){
                    q.push(make_pair(i,j));
                    Visit[i][j] = 1;
                    ++cnt;

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int idx = 0; idx < 4; idx++){
                            int nx = x + dx[idx];
                            int ny = y + dy[idx];

                            if(nx < 0 || nx >= N || ny < 0 || ny >= M || Visit[nx][ny] == 1) continue;
                            
                            if(Map[nx][ny] == 1 && Visit[nx][ny] == 0){
                                q.push(make_pair(nx,ny));
                                Visit[nx][ny] = 1;
                            }
                            
                        }

                    }
                }
            }
        }

        // PRINT_VISIT();

        cout<<cnt<<"\n";

    }



    return 0;
}