#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int house[SIZE][SIZE];
int spread[SIZE][SIZE];
bool visit[SIZE][SIZE];

int R,C,cw;

void input(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>house[i][j];
        }
    }
}

void initialize(){
    memset(spread, 0, sizeof(spread));
    memset(visit, false, sizeof(visit));

    for(int i = 0; i < R; i++){
        if(house[i][0] == -1) spread[i][0] = -1, cw = i;
    }
}

void dustDiffusion(){
    int dx[] = {-1, 0, 1, 0};   //북쪽부터 시계방향 탐색
    int dy[] = {0, 1, 0, -1};
    queue<pair<int, int> > q;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(house[i][j] != -1 && visit[i][j] == false && house[i][j] != 0){
                q.push(make_pair(i,j));
                visit[i][j] = true;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dirt = 0;       //확산되는 방향 갯수
        int diffuse = 0;    //확산되는 양
        int remain = 0;     //확산되고 남는 양, remain = house[현제] - (diffuse * dirt)
        

        diffuse = house[x][y] / 5;      //정수형

        for(int idx = 0; idx < 4; idx++){
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if(nx < R && nx >= 0 && ny < C && ny >= 0 && house[nx][ny] != -1){
                dirt++;
                spread[nx][ny] += diffuse;
            }

        }
        remain = house[x][y] - (diffuse * dirt);
        spread[x][y] += remain;
    }

    // cout<<"\n ++++++ Spread ++++++\n";
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout<<spread[i][j]<<" ";
    //     }cout<<"\n";
    // }

}

void AirPurifier(){
    //counter Clockwise, 반시계
    vector<int> v;
    int a = 0;

    for(int r = cw - 2; r >= 0; r--){
        v.push_back(spread[r][0]);
    }
    for(int c = 1; c < C; c++){
        v.push_back(spread[0][c]);
    }
    for(int r = 0; r < cw; r++){
        v.push_back(spread[r][C - 1]);
    }
    for(int c = C - 1; c > 0; c--){
        v.push_back(spread[cw - 1][c]);
    }

    // for(int i = 1; i < v.size(); i++){
    //     tmp.push_back(v[i]);
    // }
    // tmp.push_back(0);

    v.push_back(0);
    v.erase(v.begin());

    for(int r = cw - 2; r >= 0; r--){
        // spread[r][0] = tmp[a++];
        spread[r][0] = v[a++];
    }
    for(int c = 1; c < C; c++){
        spread[0][c] = v[a++];
    }
    for(int r = 0; r < cw; r++){
        spread[r][C - 1] = v[a++];
    }
    for(int c = C - 1; c > 0; c--){
        spread[cw - 1][c] = v[a++];
    }

    //Clockwise, 시계방향
    vector<int> v2;
    int b = 0;

    for(int r = cw + 1; r < R; r++){
        v2.push_back(spread[r][0]);
    }
    for(int c = 0; c < C; c++){
        v2.push_back(spread[R - 1][c]);
    }
    for(int r = R - 1; r >= cw; r--){
        v2.push_back(spread[r][C - 1]);
    }
    for(int c = C - 1; c > 0; c--){
        v2.push_back(spread[cw][c]);
    }

    v2.push_back(0);
    v2.erase(v2.begin());

    for(int r = cw + 1; r < R; r++){
        spread[r][0] = v2[b++];
    }
    for(int c = 0; c < C; c++){
        spread[R - 1][c] = v2[b++];
    }
    for(int r = R - 1; r >= cw; r--){
        spread[r][C - 1] = v2[b++];
    }
    for(int c = C - 1; c > 0; c--){
        spread[cw][c] = v2[b++];
    }


    // cout<<"\n ++++++ Move ++++++\n";
    // for(int i = 0; i < R; i++){
    //     for(int j = 0; j < C; j++){
    //         cout<<spread[i][j]<<" ";
    //     }cout<<"\n";
    // }
}

void synchronization(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            house[i][j] = spread[i][j];
        }
    }
}

int dustSum(){
    int sum = 0;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(spread[i][j] != -1) sum += spread[i][j];
        }
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;

    cin>>R>>C>>T;

    input();

    for(int i = 0; i < T; i++){
        initialize();       //visit, spread 초기화
        dustDiffusion();    //1. 미세먼지 확산
        AirPurifier();      //2. 공기청정기 작동
        synchronization();  //1,2의 결과를 house에 동기화
    }

    cout<<dustSum()<<"\n";


    return 0;
}