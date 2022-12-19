#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int n,m;
int v[51][51];
int visited[51][51];
int rooms[2504];

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int main(){
    FASTIO;
    queue<pair<int, int> > q;
    int roomCnt = 0;
    int mlarge = 0;
    int dlarge = 0;

    cin>>m>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;

            q.push({i,j});
            // cout<<"i:"<<i<<", j:"<<j<<"\n";
            roomCnt++;
            int mcnt = 0;
            visited[i][j] = roomCnt;

            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                mcnt++;
                mlarge = max(mlarge, mcnt);
                
                for(int k = 0; k < 4; k++){
                    if(!(v[r][c] & (1<<k))){
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                        if(visited[nr][nc]) continue; 
                        q.push({nr,nc});
                        visited[nr][nc] = roomCnt;
                    }
                }
            }

            rooms[roomCnt] = mcnt;

        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<visited[i][j]<<" ";
    //     }cout<<"\n";
    // }cout<<"\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i+1 < n){
                int a = visited[i+1][j];
                int b = visited[i][j];
                if(a!=b){
                    dlarge = max(dlarge, rooms[a] + rooms[b]);
                }
            }
            if(j+1 < m){
                int a = visited[i][j+1];
                int b = visited[i][j];
                if(a!=b){
                    dlarge = max(dlarge, rooms[a] + rooms[b]);
                }
            }
        }
    }

    cout<<roomCnt<<"\n";
    cout<<mlarge<<"\n";
    cout<<dlarge<<"\n";

    return 0;
}