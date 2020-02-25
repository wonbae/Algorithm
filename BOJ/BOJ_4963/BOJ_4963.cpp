#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int w, h;
int Map[SIZE][SIZE];
bool visit[SIZE][SIZE];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void BFS(){
    int land = 0;
    queue<pair<int, int> > q;
    memset(visit, false, sizeof(visit));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!visit[i][j] && Map[i][j] == 1){
                q.push(make_pair(i,j));
                visit[i][j] = true;
                land++;

                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 8; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                        if(visit[nx][ny]) continue;
                        if(Map[nx][ny] == 0) continue;

                        q.push(make_pair(nx,ny));
                        visit[nx][ny] = true;
                        
                    }
                }
            }
        }
    }
    cout<<land<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0) break;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin>>Map[i][j];
            }
        }

        BFS();

    }


    return 0;
}