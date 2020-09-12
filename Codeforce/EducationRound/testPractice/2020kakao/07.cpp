#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<assert.h>
using namespace std;

#define INF 1234567890
#define ll long long

struct State {
    int y, x, d;
};

int N;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int err[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; //시계면 nd, 반시계면 d
queue<State> q;
int dist[111][111][5];
vector<vector<int> > g;

bool Check(int y, int x, int d)
{
    if (y < 0 || x < 0 || y >= N || x >= N) return false;
    int ny = y + dir[d][0], nx = x + dir[d][1];
    if (ny < 0 || nx < 0 || ny >= N || nx >= N) return false;
    if (g[y][x] == 1 || g[ny][nx] == 1) return false;
    return true;
}

bool NoError(int y, int x)
{
    if (y < 0 || x < 0 || y >= N || x >= N) return false;
    if (g[y][x] == 1) return false;
    return true;
}

int solution(vector<vector<int>> board) {
    memset(dist, -1, sizeof(dist));
    g = board;
    N = g.size();
    
    q.push({0, 0, 0});
    dist[0][0][0] = 0;
    while(!q.empty())
    {
        State n = q.front(); q.pop();
        int y = n.y, x = n.x, d = n.d;
        if ((y==N-1 && x==N-1) || (y+dir[d][0]==N-1 && x+dir[d][1]==N-1))
            return dist[y][x][d];
        
        int ny, nx, nd, ey, ex;
        //이동
        for(int i=0; i<4; i++)
        {
            ny = y + dir[i][0], nx = x + dir[i][1], nd = d;
            if (Check(ny, nx, nd) && dist[ny][nx][nd] == -1)
            {
                q.push({ny, nx, nd});
                dist[ny][nx][nd] = dist[y][x][d] + 1;
            }
        }
        //시계
        ny = y, nx = x, nd = (d+1)%4;
        ey = y+err[nd][0], ex = x+err[nd][1];
        if (Check(ny, nx, nd) && dist[ny][nx][nd] == -1 && NoError(ey, ex))
        {
            q.push({ny, nx, nd});
            dist[ny][nx][nd] = dist[y][x][d] + 1;
        }
        
        //반시계
        ny = y, nx = x, nd = (d+3)%4;
        ey = y+err[d][0], ex = x+err[d][1];
        if (Check(ny, nx, nd) && dist[ny][nx][nd] == -1 && NoError(ey, ex))
        {
            q.push({ny, nx, nd});
            dist[ny][nx][nd] = dist[y][x][d] + 1;
        }
        
        //축 변경
        int ry = y + dir[d][0], rx = x + dir[d][1], rd = (d+2)%4;
        
        //시계
        ny = ry, nx = rx, nd = (rd+1)%4;
        ey = ry+err[nd][0], ex = rx+err[nd][1];
        if (Check(ny, nx, nd) && dist[ny][nx][nd] == -1 && NoError(ey, ex))
        {
            q.push({ny, nx, nd});
            dist[ny][nx][nd] = dist[y][x][d] + 1;
        }
        
        //반시계
        ny = ry, nx = rx, nd = (rd+3)%4;
        ey = ry+err[rd][0], ex = rx+err[rd][1];
        if (Check(ny, nx, nd) && dist[ny][nx][nd] == -1 && NoError(ey, ex))
        {
            q.push({ny, nx, nd});
            dist[ny][nx][nd] = dist[y][x][d] + 1;
        }
    }
    return -1;
}
[출처] 2020 카카오 블라인드 채용 KAKAO BLIND RECRUITMENT 후기|작성자 AM