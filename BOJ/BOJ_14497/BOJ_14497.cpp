#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
char v[301][301];
int visited[301][301];
int n, m, res;
int x1, y1, x2, y2;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    x1--, y1--, x2--, y2--;

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    q.push(1000*x1 + y1);    
    visited[x1][y1] = 1;
    int cnt = 0;

    while(v[x2][y2] != '0'){
        cnt++;
        queue<int> tmp;

        while(!q.empty()){
            int r = q.front()/1000;
            int c = q.front()%1000;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc]) continue;
                visited[nr][nc] = cnt;
                if(v[nr][nc] != '0'){
                    tmp.push(1000*nr + nc);
                    v[nr][nc] = '0';
                }else q.push(1000*nr+nc);
            }
        }
        q=tmp;
    }

    cout<<visited[x2][y2]<<"\n";

    return 0;
}