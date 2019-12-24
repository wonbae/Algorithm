#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int Map[MAX][MAX] = {0,};
int visit[MAX][MAX] = {0,};
int M, N;
int K;
vector<int> cnt;

void init() {
    int x1, y1, x2, y2;

    while(K--){
        // (0,2), (4,4)
        cin>>x1>>y1>>x2>>y2;
        
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                Map[y][x] = 1;
                visit[y][x] = 1;
            }
        }
        
    }
    
}

void BFS(){
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    queue<pair<int, int> > q;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(visit[i][j] == 0 && Map[i][j] == 0){
                q.push(make_pair(i,j));
                visit[i][j] = 1;
                int count = 1;

                // cout<<"\n==== visit =====\n";
                // for(int i = 0; i < M; i++){
                //     for(int j = 0; j < N; j++)
                //     {
                //         cout<<visit[i][j];
                //     }cout<<"\n";
                // }

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx >= 0 && nx < M && ny >= 0 && ny < N){
                            if(Map[nx][ny] == 0 && visit[nx][ny] == 0){
                                q.push(make_pair(nx,ny));
                                visit[nx][ny] = 1;
                                count++;
                            }
                        }
                            
                    }
                }
                cnt.push_back(count);
            }
        }
    }
}

int main(){

    cin>>M>>N>>K;

    init();

    // cout<<"\n==== Map =====\n";
    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < N; j++)
    //     {
    //         cout<<Map[i][j];
    //     }cout<<"\n";
    // }

    // cout<<"\n==== visit =====\n";
    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < N; j++)
    //     {
    //         cout<<visit[i][j];
    //     }cout<<"\n";
    // }

    BFS();

    sort(cnt.begin(), cnt.end());
    int size = cnt.size();

    cout<<size<<"\n";

    for(int i = 0; i < size; i++){
        cout<<cnt[i]<<" ";
    }
            
    return 0;
}