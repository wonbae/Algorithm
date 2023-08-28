#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int n, m, ans = 0;
    cin>>n>>m;

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false)); 

    int startX, startY;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
            if(v[i][j] == 'I'){
                startX = i;
                startY = j;
            }
        }
    }

    queue<pair<int, int>> q;

    q.push({startX, startY});
    visited[startX][startY] = 1;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        visited[r][c] = true;

        if(v[r][c] == 'P'){
            ans++;
        }

        for(int idx = 0; idx < 4; idx++){
            int nr = r + dx[idx];
            int nc = c + dy[idx];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(visited[nr][nc]) continue;
            if(v[nr][nc] == 'X') continue;

            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    if(ans == 0)
        cout<<"TT\n";
    else
        cout<<ans;

    return 0;
}