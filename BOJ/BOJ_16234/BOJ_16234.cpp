#include<bits/stdc++.h>
using namespace std;

#define SIZE 50

int N, L, R;
int nation[SIZE][SIZE];
int isUnion[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int day;
bool again;

struct POS{
    int x,y;
};

void migrate(vector<pair<int, int> > v_index, int nation_sum){      //이주
    int avg = int(nation_sum / v_index.size());

    for(int i = 0; i < v_index.size(); i++){
        nation[v_index[i].first][v_index[i].second] = avg;
    }
}

void borderOpen(){       //열린 국경 확인 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            bool open = false;
            queue<pair<int, int> > q;
            vector<pair<int, int> > v;
            int vsum = 0;

            if(isUnion[i][j] == 0){

                q.push(make_pair(i, j));
                isUnion[i][j] = 1;

                v.push_back(make_pair(i, j));
                vsum += nation[i][j];

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int dir = 0; dir < 4; ++dir){
                        int nr = r + dx[dir];
                        int nc = c + dy[dir];

                        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                        if(isUnion[nr][nc] != 0) continue;

                        int diff = abs(nation[nr][nc] - nation[r][c]);
                        if(diff <= R && diff >= L){
                            q.push(make_pair(nr, nc));
                            isUnion[nr][nc] = 1;
                            open = true, again = true;

                            v.push_back(make_pair(nr, nc));
                            vsum += nation[nr][nc];
                        }
                    }
                }

                if(open){
                    migrate(v, vsum);
                }else{
                    v.clear();
                    vsum = 0;
                }
            }
        }
    }
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

    again = true;
    while(again){
        again = false;
        memset(isUnion, 0, sizeof(isUnion));

        borderOpen();
        if(again) day++;
    }
    
    cout<<day<<"\n";

    return 0;
}