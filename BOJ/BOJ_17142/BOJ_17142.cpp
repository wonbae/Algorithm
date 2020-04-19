#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define SIZE 51

using namespace std;

int N, M;
int Map[SIZE][SIZE], dist[SIZE][SIZE];
vector<pair<int, int> > virus;
vector<pair<int, int> > v;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int total_area;
int ans = 987654321;

void spreadVirus(vector<pair<int, int> > vi){
    int viruscnt = 0, times = 0;
    queue<pair<int, int> > q;

    for(int i = 0; i < virus.size(); i++){
        dist[virus[i].first][virus[i].second] = -1;

        for(int j = 0; j < vi.size(); j++){
            dist[vi[j].first][vi[j].second] = 0;
            q.push(make_pair(vi[j].first, vi[j].second));
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int idx = 0; idx < 4; idx++){
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(Map[nx][ny] == 1) continue;

            if(Map[nx][ny] != 1 && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                if(Map[nx][ny] == 0){
                    viruscnt += 1;
                    times = dist[nx][ny];
                }
                q.push(make_pair(nx, ny));
            }
        }
    }

    if(viruscnt == total_area){
        if(ans > times) ans = times;
    }

}

void nCr(int idx, int cnt){
   if(cnt == M){
       memset(dist, -1, sizeof(dist));
       spreadVirus(v);
       return ;
   }

   for(int i = idx; i < virus.size(); i++){
       v.push_back(make_pair(virus[i].first, virus[i].second));
       nCr(i + 1, cnt + 1);
       v.pop_back();
   }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>Map[i][j];
            if(Map[i][j] == 2) virus.push_back(make_pair(i, j));
            if(Map[i][j] == 0) total_area += 1;
        }
    }

    nCr(0, 0);

    if(ans == 987654321) cout<<-1<<"\n";
    else cout<<ans<<"\n";

    return 0;
}