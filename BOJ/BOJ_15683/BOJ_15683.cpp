#include<bits/stdc++.h>
using namespace std;
#define SIZE 8

struct info{
    int r, c, d;
};

int N, M;
int office[SIZE][SIZE];
bool visit[SIZE][SIZE];
info cctv[SIZE][SIZE];

int dxy1[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dxy2[2][4] = {{0, -1, 0, 1}, {-1, 0, 1, 0}};
int dxy3[4][4] = {{1, 0, 0, 1}, {0, 1, -1, 0}, {-1, 0, 0, -1}, {0, -1, 1, 0}};
int dxy4[4][6] = {{0, -1, -1, 0, 0, 1}, {-1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, -1}, {1, 0, 0, -1, -1, 0}};
int dxy5[1][8] = {{-1, 0, 0, 1, 1, 0, 0, -1}};

void BFS(int dir){
    queue<pair<int, int> > q;

    while(!q.empty()){

    }
}

bool check[8];
vector<int> dirlist;

void dfs(vector<info> v, int cnt){
    if(cnt == v.size()){
        BFS();
        return ;
    }
    for(int i = 0; i < v.size(); i++){
        if(check[i] == true) continue;

        if(v[i].d == 1){
            dfs(v, cnt + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<info> v;
    info tmp;
    cin>>N>>M;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin>>office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6){
                cctv[i][j].d = office[i][j], cctv[i][j].r = i, cctv[i][j].c = j;
                tmp.r = i, tmp.c = j, tmp.d = office[i][j];
                v.push_back(tmp);
            }
        }
    }

    dfs(v, 0);


    return 0;
}