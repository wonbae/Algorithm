#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int R, C, T;
    int map[100][51] = {0,};
    int visit[100][51] = {0,};

    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};   // 시계방향
    int dy[] = {1, 0, -1, 0};  
    

    cin>>R>>C>>T;

    // fill(map, map + )
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>map[i][j];
        }
    }

    // 기능 1 실행 후 기능 2 실행, T번 반복
    for(int time = 0; time < T; time++){
        
        //기능 1 : 미세먼지 확산
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(map[i][j] != -1 && map[i][j] != 0){        //공기청소기(-1), 0 이 아님 시작
                    q.push(make_pair(i,j));     // 시작점
                    // visit[i][j] = 1;
                }else if(map[i][j] == -1){
                    visit[i][j] = -1;
                }

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    int dirc_count = 0; 

                    q.pop();

                    cout<<"\n\n( "<<x<<", "<<y<<") -> "<<map[x][y];

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];
                        
                        if(nx < 0 || nx > R || ny < 0 || ny > C) continue;    // R * C 범위 벗어나면 패스
                        if(map[nx][ny] == -1 || visit[nx][ny] == -1) continue;     // 공기청정기 만나면 패스
                        // if(visit[][] == 1) continue;        // 방문한 미세먼지면 패스
                        
                        if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                            visit[nx][ny] += (map[x][y] / 5);
                            dirc_count++;

                            cout<<"\n"<<"확산량 : "<<map[x][y] / 5<<" ";
                        }
                        
                        
                    }
                    cout<<"\n"<<"퍼진 방향수 : "<<dirc_count<<" ";
                    map[x][y] = (map[x][y] - ((map[x][y] / 5) * dirc_count));
                    cout<<"\n"<<"남은 먼지 : "<<map[x][y]<<" ";
                }
                
            }

        }
        
        cout<<"\n++++++++++++  Map Print  +++++++++++++++\n";
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cout<<map[i][j]<<" ";
            }cout<<"\n";
        }
    
        cout<<"\n++++++++++++  Visit Print  +++++++++++++++\n";
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cout<<visit[i][j]<<" ";
            }cout<<"\n";
        }

        // map = map + visit
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(map[i][j] == -1) continue;
                map[i][j] += visit[i][j];
            }
        }

        //기능 2 : 공기청정기 작동
        int air_top, air_down; 
        for(int i = 0; i < R; i++){
            if(map[i][0] == -1){
                air_top = i;
                air_down = i + 1;
                map[air_top - 1][0] = 0;
            }
        }
        

        
    }

    

    cout<<"\n++++++++++++ Map =  Map + Visit Print  +++++++++++++++\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<map[i][j]<<" ";
        }cout<<"\n";
    }
    
    

    return 0;
}