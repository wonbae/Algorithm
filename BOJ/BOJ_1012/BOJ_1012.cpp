#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int t, m, n, k;
    cin>>t;

    while(t--){
        int cnt = 0;
        cin>>m>>n>>k;
        // v.resize(n, vector<int>(m,0));
        // vist.resize(n, vector<int>(m,0));
        vector<vector<int> > v(n, vector<int>(m,0));
        vector<vector<int> > vist(n, vector<int>(m,0));


        for(int i = 0; i < k; i++){
            int x,y;
            cin>>y>>x;
            v[x][y] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                queue<pair<int,int> > q;
                if(v[i][j] && !vist[i][j]){
                    q.push({i,j});
                    vist[i][j] = 1;
                    cnt++;

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int idx = 0; idx < 4; idx++){
                            int nx = x + dx[idx];
                            int ny = y + dy[idx];
                            if(nx < 0 || ny >= m || ny < 0 || nx >= n) continue;
                            if(v[nx][ny] && !vist[nx][ny]){
                                q.push({nx,ny});
                                vist[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}