#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std; 
#define MAX 101

int map[MAX][MAX] = {0,};
int visit[MAX][MAX] = {0,};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int M, N, K;
    cin>>M>>N>>K;
    
    vector<int> ans;

    for(int i = 0; i < K; i++){

        int lx, ly, rx, ry;
        cin>>lx>>ly>>rx>>ry;

        for(int x = lx; x < rx; x++){
            for(int y = ly; y < ry; y++){
                map[y][x] = 1;
                visit[y][x] = 1;
            }
        }
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    queue<pair<int,int> > q;
    

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0 && visit[i][j] == 0){
                q.push(make_pair(i, j));
                visit[i][j] = 1;
                int cnt = 1;

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nr = r + dx[idx];
                        int nc = c + dy[idx];

                        if(nr >= 0 && nr < M && nc >= 0 && nc < N){
                            if(map[nr][nc] == 0 && visit[nr][nc] == 0){
                                q.push(make_pair(nr,nc));
                                visit[nr][nc] = 1;
                                cnt++;
                            }
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout<<ans.size()<<"\n";

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}