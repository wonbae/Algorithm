#include<bits/stdc++.h>
using namespace std;
#define SIZE 501

int N, M;
int board[SIZE][SIZE];
int ans;

const int block[19][4][2] = {
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},   //ㅁ
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},   //ㅡ
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},   //2
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 1}, {1, 0}, {1, 2}},   //ㅗ
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},   // ㄴ
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
};

void tetromino(int r, int c){
    for(int i = 0; i < 19; i++){
        int res = 0;
        for(int j = 0; j < 4; j++){
            int nr = r + block[i][j][0];
            int nc = c + block[i][j][1];

            if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                res += board[nr][nc];
            }
        }
        if(res > ans) ans = res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            tetromino(i, j);
        }
    }

    cout<<ans<<"\n";

    return 0;
}