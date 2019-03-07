#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
queue <pair<int,int>> q;
int map[16][16] = { 0 };
bool visited[16][16] = { 0 };

const int dx[4] = { 1, 0, -1,  0 };//방향벡터
const int dy[4] = { 0, 1, 0, -1 };//아래쪽,오른쪽,위쪽,왼쪽

void init() {//초기화
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    while (!q.empty()) q.pop();
}

int bfs(int a, int b) {
    q.push(make_pair(a, b));
    while (!q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visited[x][y] = true;
        for (int z = 0; z < 4; z++) {
            int next_x = x + dx[z];
            int next_y = y + dy[z];
            if (next_x < 0 || next_y < 0 || next_x >= 16 || next_y >= 16) continue;
            if (map[next_x][next_y] == 0&&!visited[next_x][next_y]) {
                q.push(make_pair(next_x, next_y));
            }
            else if (map[next_x][next_y] == 3) return 1;
        }
    }
    return 0;
}

int main() {
    int num;
    for (int t = 1; t <= 10; t++) {
        cin >> num;
        int a=0, b=0;
        init();
        for (int i = 0; i < 16; i++)
            for (int j = 0; j < 16; j++)
            {
                scanf("%1d", &map[i][j]);
                if (map[i][j] == 2) { a = i, b = j; }//출발점위치
            }
        cout<<"#"<<num<<' '<<bfs(a, b)<<'\n';
    }
}