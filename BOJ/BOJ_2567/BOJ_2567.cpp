// 색종이-2 둘레 구하기

#include<bits/stdc++.h>
using namespace std;

bool board[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    int T;
    int cnt = 0;

    cin>>T;

    while(T--){
        int x, y;
        cin>>x>>y;

        for(int r = y; r < y + 10; r++){
            for(int c = x; c < x + 10; c++){
                if(board[r][c]) continue;
                board[r][c] = 1; 
            }
        }
    }

    // for(int r = 0; r < 50; r++){
    //     for(int c = 0; c < 50; c++){
    //         cout<<board[r][c]<<" ";
    //     }cout<<"\n";
    // }

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){

            if(board[i][j]) continue;

            for(int idx = 0; idx < 4; idx++){
                int nx = i + dx[idx];
                int ny = j + dy[idx];

                if(nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
                if(!board[nx][ny]) continue;    //0이면 쌩깜
                cnt++;
            }
        }
    }

    cout<<cnt<<"\n";

    return 0;
}