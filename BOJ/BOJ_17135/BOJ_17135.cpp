// boj_17135 Castle Defense G4
#include<bits/stdc++.h>
using namespace std;
#define SIZE 16

typedef pair<int, pair<int, int> > piii;    //1. distance 2.column 3.row 
int N, M, D;
int Map[SIZE][SIZE];
int answer;

int distance(int nx, int ny, int x, int y){     //두 점 사이의 거리
    return abs(nx - x) + abs(ny - y);
}

void kill(){    //누굴 죽일지 골라볼까요
    // cout<<"\n +++++ new Archer ++++++\n";
    int tmp[SIZE][SIZE];
    int term = N;
    int ecnt = 0;
    vector<pair<int, int> > archer;
    memcpy(tmp, Map, sizeof(Map));

    for(int i = 0; i < M; i++){
        if(Map[N][i] == 2) archer.push_back(make_pair(N, i));
    }

    while(term--){
        vector<pair<int, int> > enermy;
        for(int i = 0; i < 3; i++){
            priority_queue<piii, vector<piii>, greater<piii> > q;    //1. distance 2.column 3.row / Ascending 오름차순
            for(int r = 0; r < N; r++){
                for(int c = 0; c < M; c++){
                    if(tmp[r][c] == 0) continue;
                    if(tmp[r][c] == 1){
                        int dist = distance(archer[i].first, archer[i].second, r, c);
                        if(dist <= D){
                            q.push(make_pair(dist, make_pair(c, r)));  // pair안에선 앞에꺼 먼저 비교함 그래서 c 먼저 넣음
                        } 
                    }
                }
            }
            if(!q.empty()){
                int y = q.top().second.first, x = q.top().second.second;    //주로 y를 row, x를 col로 사용하지만.. 난 반대로.. 나쁜습관임..
                // cout<<"d : "<<q2.top().first<<", r : "<<x<<", c : "<<y<<"\n";
                enermy.push_back(make_pair(x, y));
            }
        }

        //erase enermies
        for(int i = 0; i < enermy.size(); i++){
            int x = enermy[i].first, y = enermy[i].second;
            if(tmp[x][y]){
                tmp[x][y] = 0;
                ecnt++;
            }
        }

        //move down
        for(int r = N - 2; r >= 0; r--){
            for(int c = 0; c < M; c++){
                tmp[r + 1][c] = tmp[r][c];
            }
        }
        for(int c = 0; c < M; c++) tmp[0][c] = 0;
    }

    if(answer < ecnt) answer = ecnt;

}

void nCrArcher(int col, int cnt){
    if(cnt == 3){
        // for(int i = 0; i < M; i++){
        //     cout<<Map[N][i]<<" ";
        // }
        // cout<<"\n";
        kill();
        return;
    }

    for(int i = col; i < M; i++){
        if(Map[N][i] == 2) continue;

        Map[N][i] = 2;
        nCrArcher(col + 1, cnt + 1);
        Map[N][i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>D;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>Map[i][j]; 
        }
    }

    nCrArcher(0, 0);

    cout<<answer<<"\n";

    return 0;
}