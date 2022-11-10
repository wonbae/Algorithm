#include<bits/stdc++.h>
using namespace std;
#define SIZE 51

int N, board[SIZE][SIZE];

int  BFS(){
    bool flag;
    int cnt = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            flag = true;

            for(int idx = 0; idx < 4; idx++){
                int nr = r + dr[idx];
                int nc = c + dc[idx];

                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if(board[r][c] < board[nr][nc]){
                    flag = false;
                    continue;
                }
            }

            if(flag){
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int ans = 0;

    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>board[i][j];
        }
    }

    ans = BFS();
    cout<<ans<<"\n";
    return 0;
}