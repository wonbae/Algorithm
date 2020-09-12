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
using namespace std;

int g[111][111], h[111][111]; //g보 h기둥

bool Safe(int ty, int y, int x)
{
    if (ty == 0) //기둥
    {
        if (y == 0 || (x!=0 && g[y][x-1]) || g[y][x] || h[y-1][x]) return true;
        return false;
    }
    else if (ty == 1) //보
    {
        if (y && ((x!=0 && g[y][x-1] && g[y][x+1]) || h[y-1][x] || h[y-1][x+1])) return true;
        return false;
    }
}

vector<vector<int>> solution(int N, vector<vector<int>> q) {
    vector<vector<int>> res;
    for(int i=0; i<q.size(); i++)
    {
        int x, y, a, b;
        x=q[i][0];y=q[i][1];a=q[i][2];b=q[i][3];
        if (a == 0)
        {
            if (b == 0)
            {
                bool chk = true;
                h[y][x]=0;
                if (h[y+1][x] && !Safe(0, y+1, x)) chk = false;
                if (x && g[y+1][x-1] && !Safe(1, y+1, x-1)) chk = false;
                if (g[y+1][x] && !Safe(1, y+1, x)) chk = false;
                if (!chk) h[y][x] = 1;
            }
            else if (b == 1)
            {
                if (Safe(a, y, x)) h[y][x] = 1;
            }
        }
        else if (a == 1)
        {
            if (b == 0)
            {
                bool chk = true;
                g[y][x]=0;
                if (h[y][x] && !Safe(0, y, x)) chk = false;
                if (h[y][x + 1] && !Safe(0, y, x + 1)) chk = false;
                if (x && g[y][x-1] && !Safe(1, y, x-1)) chk = false;
                if (g[y][x+1] && !Safe(1, y, x+1)) chk = false;
                if (!chk) g[y][x] = 1;
            }
            else if (b == 1)
            {
                if (Safe(a, y, x)) g[y][x] = 1;
            }
        }
    }
    
    for(int i=0; i<111; i++)
        for(int j=0; j<111; j++)
        {
            if (g[i][j])
            {
                res.push_back(vector<int>());
                res.back().push_back(j);
                res.back().push_back(i);
                res.back().push_back(1);
            }
            if (h[i][j])
            {
                res.push_back(vector<int>());
                res.back().push_back(j);
                res.back().push_back(i);
                res.back().push_back(0);
            }
        }
    sort(res.begin(), res.end());
    return res;
}
// [출처] 2020 카카오 블라인드 채용 KAKAO BLIND RECRUITMENT 후기|작성자 AM