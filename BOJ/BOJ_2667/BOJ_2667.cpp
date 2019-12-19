#include<bits/stdc++.h>
using namespace std;

int Map[26][26] = {0,};
bool visit[26][26] = {false,};
int danji = 0;

vector<int> BFS(int n){
    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    vector<int> cnt;
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i][j] == false && Map[i][j] == 1){
                int count = 0;
                q.push(make_pair(i,j));
                visit[i][j] = true;
                count++;
                danji++;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx >= n && nx < 0 && ny >= n && ny < 0 && (visit[nx][ny] == true)){
                            continue;
                        }

                        if(Map[nx][ny] == 1 && visit[nx][ny] == false){
                            q.push(make_pair(nx,ny));
                            visit[nx][ny] = true;
                            count++;
                        }

                    }
                }
                cnt.push_back(count);
            }
        }
    }

    sort(cnt.begin(), cnt.end());

    return cnt;
}

int main(){
    int N;
    char input;
    vector<int> answer;

    cin>>N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>input;
            Map[i][j] = int(input - '0');
        }
    }

    answer = BFS(N);

    cout<<danji<<"\n";
    for(int i = 0; i < answer.size(); i++){
        cout<<answer[i]<<"\n";
    }

    return 0;
}