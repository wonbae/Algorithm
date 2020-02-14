#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int N, M;
int r, c, d;
int cSpace[SIZE][SIZE];         //Search Space
int cleanHere[SIZE][SIZE];     //visit
int check[SIZE][SIZE];

void initialize(){
    memset(cleanHere, 0, sizeof(cleanHere));

    cin>>N>>M;
    cin>>r>>c>>d;       //row, col, direction

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>cSpace[i][j];          // 미방문 0, 벽 1, 방문 2
            if(cSpace[i][j] == 1) cleanHere[i][j] = 1, check[i][j] = 4;
        }
    }

}

int cleaning(){
    bool flag = true;
    int cnt = 0;
    int dx[] = {-1, 0, 1, 0};   //북(0) - 동(1) - 남(2) - 서(3)
    int dy[] = {0, 1, 0, -1};

    while(flag){       // 미방문 0, 벽 1, 방문 2

        if(cSpace[r][c] == 0 && cleanHere[r][c] == 0){
            cleanHere[r][c] = 2;
            // check[r][c] = d;
            cnt++;
        }
        
        for(int i = 0; i < 5; i++){
            if(i == 4){
                int back_dx = r + dx[(d + 2) % 4];      //뒤를 보는 좌표
                int back_dy = c + dy[(d + 2) % 4];

                if(cSpace[back_dx][back_dy] == 1){      //d. 뒤가 벽이면 그만둬야지
                    flag = false;
                } 
                else{
                    r = back_dx;        //c. 벽 아니면 뒤로 빽
                    c = back_dy;
                    
                }

                break;      //이걸 해야 for문 빠져나가지 ^^
            }

            int dir = (d + 3) % 4;      //이부분이 젤 중요하지..  현제 방향 d에서 왼쪽부분은 항상 +3 위치에 있음
            int x = r + dx[dir];
            int y = c + dy[dir];

            if(cleanHere[x][y] == 0 && cSpace[x][y] == 0){      //a.
                d = dir;
                r = x;
                c = y;
                break;

            }else if(cleanHere[x][y] == 2 || cSpace[x][y] == 1){    //b.
                d = dir;
                // break;   //시발 여기서 break 때리면 안되자나!!!!
            }
        }
    }
    // cout<<"\n === cleanHere === \n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout<<cleanHere[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // cout<<"\n +++ Check +++ \n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout<<check[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    initialize();
    answer = cleaning();

    cout<<answer<<"\n";

    return 0;
}