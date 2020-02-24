#include<bits/stdc++.h>
using namespace std;
#define MAX 100

typedef struct TOMA{
    int y,x,z;

    TOMA(int y, int x, int z) : y(y), x(x), z(z)
    {

    }

}TOMA;

int tomato[MAX][MAX][MAX];
// bool visit[MAX][MAX][MAX];
int M,N,H;
queue<TOMA> Q;
int cnt = -1;

void PRINT(){
    cout<<"\n====== Print Tomato =======\n";
    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cout<<tomato[y][x][z]<<" ";
            }cout<<"\n";
        }cout<<"\n";
    }
}

bool iszero(){
    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                if(tomato[y][x][z] == 0){
                    return 1;
                }

                if(tomato[y][x][z] > cnt){
                     cnt = tomato[y][x][z];
                } 
            }
        }
    }
    return 0;
}

int main(){    
    // queue<pair<int, int> > q;
    int dy[] = {-1, 0, 1, 0, 0, 0};
    int dx[] = {0, 1, 0, -1, 0, 0};
    int dz[] = {0, 0, 0, 0, -1, 1};
    
    
    cin>>M>>N>>H;

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cin>>tomato[y][x][z];
                // if(tomato[y][x][z] == -1) visit[y][x][z] = true; 
                if(tomato[y][x][z] == 1){
                    Q.push(TOMA(y,x,z));
                    // visit[y][x][z] = true;
                }
            }
        }
    }

    while(!Q.empty()){
        int y = Q.front().y, x = Q.front().x, z = Q.front().z;
        Q.pop();

        for(int idx = 0; idx < 6; idx++){
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            int nz = z + dz[idx];
                
            if(ny < 0 || nx < 0 || nz < 0 || ny >= N || nx >= M || nz >= H) continue;
            // if(visit[ny][nx][nz]) continue;
            if(tomato[ny][nx][nz]) continue;
            if(tomato[ny][nx][nz] == -1) continue;

            // visit[ny][nx][nz] = true;
            tomato[ny][nx][nz] = tomato[y][x][z] + 1;
            Q.push(TOMA(ny, nx, nz));
            
            
        }
        // PRINT();
    }

    
    if(iszero()){
        cout<<-1<<"\n";
        return 0;
    }else{
        cout<<cnt - 1<<"\n";
        return 0;
    }

    return 0;
}