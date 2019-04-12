// #include <stdio.h>
// #include <vector>
// #include <string.h>
// using namespace std;

// pair<int, int> start;
// int check[101][101];
// int map[102][102];
// int dr[4] = {0, 1, 0, -1};
// int dc[4] = {1, 0, -1, 0};
// int flag;

// void go(int nowRow, int nowCol) {
//     if (map[nowRow][nowCol] == 3) {
//         flag = 1;
//         return;
//     }
//     check[nowRow][nowCol] = 1;
//     for (int i = 0; i < 4; i++) {
//         int nextRow = nowRow + dr[i];
//         int nextCol = nowCol + dc[i];
//         if (nextRow < 101 && nextCol < 101 && check[nextRow][nextCol] == 0
//             && (map[nextRow][nextCol] == 0 || map[nextRow][nextCol] == 3)) {
//             go(nextRow, nextCol);
//         }
//     }
// }

// int main(void) {
//     int t = 10, cnt = 1;
//     while (t--) {
//         flag = 0;
//         for (int i = 0; i < 100; i++) {
//             for (int j = 0; j < 100; j++) {
//                 scanf("%1d", &map[i][j]);
//                 if (map[i][j] == 2) {
//                     start = make_pair(i, j);
//                 }
//             }
//             char ch;
//             scanf("%c", &ch);
//         }
//         go(start.first, start.second);
//         printf("#%d %d\n", cnt++, flag);
//         memset(map, 0, sizeof(map));
//         memset(check, 0, sizeof(check));
//         flag = 0;
//     }
//     return 0;
// }



#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int map[102][102] = {0,};
int visited[101][101] = {0,};
queue <pair<int,int> > q;


int BFS(int a, int b){
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // q.push({a,b});
    q.push(pair<int,int>(a,b));
    

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        visited[a][b] = 1;

        for(int idx = 0; idx < 4; idx++){
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if(map[nx][ny] == 3){
                return 1;
            }
            if( nx < 101  && ny < 101 && map[nx][ny] == 0 && visited[nx][ny] == 0){
                // q.push({nx,ny});
                q.push(make_pair(nx,ny));
                // visited[nx][ny] = 1;
            }
        }
    }
    return 0;
}

int main(){
    // std::ios_base::sync_with_stdio(false);
    int T = 0,a = 0, b = 0;
    cin>>T;
    for(int tc = 1; tc <= 10; tc++){
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                cin>>map[i][j];
                if(map[i][j] == 2){
                    a = i;
                    b = j;
                }
            }
        }
        cout<<"#"<<tc<<" "<<BFS(a,b)<<endl;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

    }
    return 0;
}


