#include <bits/stdc++.h>
using namespace std;
#define MAX 501 //도화지 크기가 500 이니깐 하나크게

int Map[MAX][MAX] = {0,};
int row,col;
int visit[MAX][MAX] = {0,};

void init(){    // 입력받기
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin>>Map[i][j];
        }
    }
}

// void print_map(){
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             cout<<Map[i][j];
//         }
//         cout<<'\n';
//     }
// }

// void print_visit(){
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             cout<<visit[i][j];
//         }
//         cout<<'\n';
//     }
// }

void BFS(){
    int land_count = 0, max = 0, big_count = 0;
    int dx[] = {0, 0, -1, 1};   //상-하-좌-우, 시계방향으로 해도됨..
    int dy[] = {-1, 1, 0, 0};   //상-하-좌-우
    queue<pair<int, int> > q;


    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(visit[i][j] == 0 && Map[i][j] == 1){
                q.push(make_pair(i,j));
                visit[i][j] = 1;
                land_count++;    // 그림 갯수 증가
                // cout<<"("<<i<<","<<j<<") -> ";
            }

            // 방법 2
            // if(visit[i][j] || Map[i][j] == 0) continue;
            // q.push(make_pair(i,j));
            // visit[i][j] = 1;
            // land_count++;
            // cout<<"("<<i<<","<<j<<") -> ";
            
            big_count = 0;      //근접한 그림 1들을 찾기전에 초기화해줘야지 중복 안되겠지
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                big_count++;    // 큐에서 뺄때 그림의 크기 증가

                for(int idx = 0; idx < 4; idx++){
                    int nx = x + dx[idx];
                    int ny = y + dy[idx];
                    
                    if(nx < 0 && nx >= row && ny < 0 && ny >= col ) continue;   // 범위 벗어날 경우
                    if(visit[nx][ny] == 1 || Map[nx][ny] != 1) continue;    // 이미 방문했거나 1이 아닌경우

                    if(Map[nx][ny] == 1 && visit[nx][ny] == 0){     // if 안해줘도 되지만.. 방문 않했고 1이 근접일 경우 큐에추가
                        visit[nx][ny] = 1;
                        q.push(make_pair(nx,ny));     
                    }
                }
            }
            if(max < big_count){    // 큰그림 찾기
                max = big_count;
            }
            
        }
        
    }
    cout<<land_count<<'\n'<<max;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>row>>col;

    init();    // 지도 입력, 초기화
    // print_map();
    // print_visit();
    BFS();      // 탐색
    // print_visit();

    



    return 0;
}