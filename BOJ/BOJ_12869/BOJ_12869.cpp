#include<bits/stdc++.h>
using namespace std;

int dmg[64][64][64], visited[64][64][64], scv[3];
int n;
int idx[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1}
};

struct abc{
    int a, b, c;
};

queue<abc> q;

int solve(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a,b,c});
    while(!q.empty()){
        int aa = q.front().a;
        int bb = q.front().b;
        int cc = q.front().c;
        q.pop();

        for(int i = 0; i < 6; i++){
            int naa = max(0, aa - idx[i][0]);
            int nbb = max(0, bb - idx[i][1]);
            int ncc = max(0, cc - idx[i][2]);
            if(visited[naa][nbb][ncc]) continue;
            visited[naa][nbb][ncc] = visited[aa][bb][cc] + 1;
            q.push({naa,nbb,ncc});
        }
    }
    return visited[0][0][0] - 1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>scv[i];
    }

    cout<<solve(scv[0], scv[1], scv[2])<<"\n";

    return 0;
}