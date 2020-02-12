#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int N, M;
int r, c, d;
int cSpace[SIZE][SIZE];         //Search Space
bool cleanHere[SIZE][SIZE];     //visit

void initialize(){
    // memset(cSpace, 0, sizeof(cSpace));
    memset(cleanHere, false, sizeof(cleanHere));

    cin>>N>>M;
    cin>>r>>c>>d;       //row, col, direction

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>cSpace[i][j];          //빈칸은 0, 벽은 1
            if(cSpace[i][j] == 1) cleanHere[i][j] = true;
        }
    }

}

int cleaning(){
    int cnt = 0;
    queue<pair<int, int> > q;
    int dx[] = {-1, 0, 1, 0};   //서 -> 남 -> 동 -> 북 (반시계방향)
    int dy[] = {0, -1, 0, 1};
    
    q.push(make_pair(r,c));
    cleanHere[r][c] = true;

    while(!q.empty()){
        int four = 0;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int idx = 0; idx < 4; idx++){
            int dir = (d + idx) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < N && nx >= 0 && ny < M && ny >= 0){
                if(cleanHere[nx][ny] && cSpace[nx][ny] != 1){      // 청소 했다면, 회전만 하고 현제 위치에서 왼쪽을 바라본다.
                    d = dir;
                    four++;

                }else if(cleanHere[nx][ny] == false && cSpace[nx][ny] != 1){       // 청소 안했다면, 회전하고 전진하고 청소한다.
                    d = dir;
                    q.push(make_pair(nx,ny));
                    cleanHere[nx][ny] = true;
                    cnt++;
                    break;
                }

                if(four >= 4 || cSpace[nx][ny] == 1){      
                    if(four >= 4){
                        int tmpx = nx + dx[(dir + 2) % 4];
                        int tmpy = ny + dy[(dir + 2) % 4];

                        if(cSpace[tmpx][tmpy] != 1){
                            q.push(make_pair(tmpx, tmpy));
                            cleanHere[tmpx][tmpy] = true;
                            break;
                        }else{
                            cout<<"\n-- End --\n";
                            return 0;
                        }
                    }
                }
            }
            
        }
    }

    int res = 0;
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            if(cleanHere[i][j]){
                res++;
            }
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    initialize();
    answer = cleaning();

    cout<<answer<<"\n";

    return 0;
}