#include<bits/stdc++.h>
using namespace std;

#define SIZE 50

inline int abs(int nx, int x, int ny, int y){
    int x_tmp = nx > x ? (nx - x) : (x - nx);
    int y_tmp = ny > y ? (ny - y) : (y - ny);
    return x_tmp + y_tmp;
}

inline int min(int a, int b){
    return a > b ? b : a;
}

typedef struct NUMBER{
    int x;
    int y;
    int cnt;
    // void NUMBER(){} : x(x) , y(y) , cnt(cnt);
}NUMBER;

int City[SIZE][SIZE] = {0,};
int Visit[SIZE][SIZE] = {0,};
int Check[SIZE][SIZE] = {0,};
int N, M;   //N <= 50, M <= 13
vector<NUMBER> numbering;

void BFS(){
    int dist = 987654321, count = 0;
    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(City[i][j] == 1){
                q.push(make_pair(i,j));
                Visit[i][j] = 1;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                        if(City[nx][ny] == 0 && Visit[nx][ny] == 0){
                            q.push(make_pair(nx,ny));
                            Visit[nx][ny] = 1;
                        }

                        if(City[nx][ny] == 2 && Visit[nx][ny] == 0){
                            // |nx - x| + |ny - y|
                            dist = min(abs(nx,x,ny,y), dist);
                            Check[nx][ny] += 1;
                            count++;
                            numbering.push_back(NUMBER(nx,ny,count));
                        }
                    }
                    
                }
            }
        }
    }




}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>City[i][j];
            if(City[i][j] == 1) Visit[i][j] = 1;    //home
            if(City[i][j] == 2) Visit[i][j] = 2;    //chicken
        }
    }

    BFS();



    return 0;
}