#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<vector<int> > v(N, vector<int> (N, 0));
    vector<vector<int> > visit(N, vector<int> (N, 0));
    vector<int> ans;
    char input;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>input;
            v[i][j] = int(input - '0');
        }
    }

    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(v[i][j] && !visit[i][j]){
                q.push(make_pair(i,j));
                visit[i][j] = 1;
                int cnt= 1;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                            if(v[nx][ny] && !visit[nx][ny]){
                                q.push(make_pair(nx,ny));
                                visit[nx][ny] = 1;
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
        cout<<ans[i]<<"\n";
    }


    return 0;
}