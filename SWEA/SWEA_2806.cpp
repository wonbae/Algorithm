#include<iostream>
#include<queue>

using namespace std;

#define SIZE 10

int main(){
    int T;
    // x축 y축 2차원 평면 기준이 아닌, 2차원 배열의 인덱스 기준으로 방향을 생각한거임
    int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};    //상 - 우 - 하 - 좌 - 좌상 - 우하 - 좌하 - 우상
    int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
    queue<pair<int, int> > q;

    cin>>T;

    for(int tc = 1; tc <= T; tc++){
        int answer = 0;
        int N;

        int map[SIZE][SIZE] = {0,};
        bool visit[SIZE][SIZE] = {false,};  

        cin>>N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visit[i][j] == false){
                    q.push(make_pair(i,j));
                    visit[i][j] = true;
                    answer++;

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int dir = 0; dir < 8; dir++){
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];

                            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny] == true) continue;

                            for(int n = 0; n < N; n++){
                                visit[nx][ny] = true;
                                nx += dx[dir];
                                ny += dy[dir];
                            }
                        }
                    }
                    
                }
            }
        }





        cout<<"#"<<tc<<" "<<answer<<"\n";
    }




    return 0;
}