#include<bits/stdc++.h>
using namespace std;

#define SIZE 50

int N, L, R;
int nation[SIZE][SIZE];
int isUnion[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int day;
bool again = true;

void migrate(vector<pair<int, int> > pcnt, int psum){      //이주
    int avg = int(psum / pcnt.size());
    for(int i = 0; i < pcnt.size(); i++){
        nation[pcnt[i].first][pcnt[i].second] = avg;
    }
    memset(isUnion, 0, sizeof(isUnion));
}

bool border(){       //열린 국경 확인 
    queue<pair<int, int> > q;
    bool open = false;
    again = false;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            int people = 0, sum = 0;
            open = false;
            vector<pair<int, int> > v;

            if(isUnion[i][j] == 0){
                q.push(make_pair(i, j));
                isUnion[i][j] = 1;
                
                v.push_back(make_pair(i, j));
                people += nation[i][j];
            
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(isUnion[nx][ny] != 0) continue;
                        int diff = abs(nation[nx][ny] - nation[x][y]);
                        if(diff < L || diff > R) continue;

                        isUnion[nx][ny] = 1;
                        open = true;
                        again = true;
                        q.push(make_pair(nx, ny));
                    }
                }

                if(!open){
                    people -= nation[i][j];
                    v.pop_back();
                }else{
                    migrate(v, people);
                    v.clear();
                    people = 0;
                }
            }
        }
    }
    return again;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin>>N>>L>>R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>nation[i][j];
        }
    }

    while(again){
        memset(isUnion, 0, sizeof(isUnion));

        if(border()){
            day++;
        }else break;
    }
    
    cout<<day<<"\n";
    

    return 0;
}