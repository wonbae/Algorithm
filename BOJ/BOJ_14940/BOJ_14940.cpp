#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int arr[1004][1004];
int visited[1004][1004];
// int res[1004][1004];
int n, m;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = 0;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(arr[nr][nc] == 0){
                continue;
            }
            if(visited[nr][nc] != -1) continue;

            q.push({nr,nc});
            visited[nr][nc] = visited[r][c] + 1;
            
        }
    }
    return ;
}

int main(){
    fastio;
    memset(visited, -1, sizeof(visited));

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 2){
                bfs(i, j);
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0 || arr[i][j] == 2){
                // res[i][j] = 0;
                cout<<0<<" ";
            }else{
                if(visited[i][j] == -1){
                    // res[i][j] = -1;
                    cout<<-1<<" ";
                }else{
                    // res[i][j] = visited[i][j];
                    cout<<visited[i][j]<<" ";
                }
            }
        }cout<<"\n";
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<res[i][j]<<" ";
    //     }cout<<"\n";
    // }

    return 0;
}