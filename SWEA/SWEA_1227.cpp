#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

pair<int, int> start;
int check[101][101];
int map[102][102];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int flag;

void go(int nowRow, int nowCol) {
    if (map[nowRow][nowCol] == 3) {
        flag = 1;
        return;
    }
    check[nowRow][nowCol] = 1;
    for (int i = 0; i < 4; i++) {
        int nextRow = nowRow + dr[i];
        int nextCol = nowCol + dc[i];
        if (nextRow < 101 && nextCol < 101 && check[nextRow][nextCol] == 0
            && (map[nextRow][nextCol] == 0 || map[nextRow][nextCol] == 3)) {
            go(nextRow, nextCol);
        }
    }
}

int main(void) {
    int t = 10, cnt = 1;
    while (t--) {
        flag = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                scanf("%1d", &map[i][j]);
                if (map[i][j] == 2) {
                    start = make_pair(i, j);
                }
            }
            char ch;
            scanf("%c", &ch);
        }
        go(start.first, start.second);
        printf("#%d %d\n", cnt++, flag);
        memset(map, 0, sizeof(map));
        memset(check, 0, sizeof(check));
        flag = 0;
    }
    return 0;
}
[출처] SWEA D4] 1227. [S/W 문제해결 기본] 7일차 - 미로2|작성자 1ilsang