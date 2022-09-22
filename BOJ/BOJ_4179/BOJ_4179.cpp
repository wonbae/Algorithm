#include<bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int INF = 987654321;
int maze[1004][1004], fire[1004][1004], person[1004][1004];
queue<pair<int,int> > fq;
queue<pair<int,int> > q;
int posx, posy, r, c, res;

bool isrange(int a, int b){
    return a >= 0 && b >= 0 && a < r && b < c;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>r>>c;

    fill(&fire[0][0], &fire[0][0] + 1004*1004, INF);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char ch;
            cin>>ch;
            if(ch=='#'){
                maze[i][j] = 1;
            }else if(ch=='.'){
                maze[i][j] = 0;
            }else if(ch=='F'){
                fire[i][j] = 1;
                fq.push({i,j});
            }else{
                posx = i, posy = j;
            }
        }
    }

    //fire spread
    while(!fq.empty()){
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!isrange(nx, ny)) continue;
            if(fire[nx][ny] != INF || maze[nx][ny]==1) continue;
            fire[nx][ny] = fire[x][y] + 1;
            fq.push({nx,ny});
        }
    }

    //human spread
    q.push({posx, posy});
    person[posx][posy] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == 0 || y == 0 || x == r-1 || y == c-1){
            res = person[x][y];
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!isrange(nx,ny)) continue;
            if(person[nx][ny] || maze[nx][ny] == 1) continue;
            if(fire[nx][ny] <= person[x][y] + 1) continue;
            person[nx][ny] = person[x][y]+1;
            q.push({nx,ny});
        }
    }

    if(res!=0){
        cout<<res<<"\n";
    }else{
        cout<<"IMPOSSIBLE \n";
    }

    return 0;
}