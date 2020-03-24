#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

struct info{
    bool rc;    // 상어가 존재 하냐 아니냐
    int s, d, z;    // 상어의 속도, 방향, 크기
};

info Map[SIZE + 1][SIZE + 2];
int R,C,M;
int sumShark;
const int dx[] = {-1, 1, 0, 0};     //d : 1 위, 2 아래, 3 우, 4 좌
const int dy[] = {0, 0, 1, -1};

void huntingShark(int col){
    for(int r = 1; r <= R; r++){
        if(Map[r][col].rc == true){
            sumShark += Map[r][col].z;
            Map[r][col].rc = false;
            break;
            // Map[r][col].s = 0;
            // Map[r][col].d = 0;
            // Map[r][col].z = 0;
        }
    }
}

void moveShark(){
    info copy[SIZE + 1][SIZE + 2] = {0};

    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            if(Map[r][c].rc){   //(r,c)에 상어가 존재하고 방문한적이 없다면 move
                int s = 0;
                int d = Map[r][c].d;
                int new_r = r;
                int new_c = c;

                if(d == 1 || d == 2){       //위 아래
                    s = Map[r][c].s % ((R - 1) * 2);

                    while(s--){
                        if(r == 0 && d == 1) d = 2;
                        if(r == R && d == 2) d = 1;
                        new_r += dx[d - 1];
                    }
                    
                    if(copy[new_r][c].rc == true){       // 새로 갈려는 곳에 상어가 있다면 크기 비교
                        if(Map[r][c].z > copy[new_r][c].z){      // 옮길려고 하는 상어 크기 > 원래 있던 상어 크기
                            copy[new_r][c].rc = true;
                            copy[new_r][c].s = s;
                            copy[new_r][c].d = d;
                            copy[new_r][c].z = Map[r][c].z;
                            Map[r][c].rc = false;
                        }
                    }else{      // 갈려는 곳에 상어가 없음 그냥 옮기면 됨,
                        copy[new_r][c].rc = true;
                        copy[new_r][c].s = s;
                        copy[new_r][c].d = d;
                        copy[new_r][c].z = Map[r][c].z;
                        Map[r][c].rc = false;
                    }


                }else{      // 좌 우
                    s = Map[r][c].s % ((C - 1) * 2);

                    while(s--){
                        if(c == 0 && d == 4) d = 3;
                        if(c == C && d == 3) d = 4;
                        new_c += dy[d - 1];
                    }

                    if(copy[r][new_c].rc){
                        if(Map[r][c].z > copy[r][new_c].z){
                            copy[r][new_c].rc = true;
                            copy[r][new_c].s = s;
                            copy[r][new_c].d = d;
                            copy[r][new_c].z = Map[r][c].z;
                            Map[r][c].rc = false;
                        }
                    }else{
                        copy[r][new_c].rc = true;
                        copy[r][new_c].s = s;
                        copy[r][new_c].d = d;
                        copy[r][new_c].z = Map[r][c].z;
                        Map[r][c].rc = false;
                    }
                }
                
            }
        }
    }
    memcpy(Map, copy, sizeof(copy));
    cout<<"\n++++++ copy +++++++\n";
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<copy[i][j].rc<<" ";
        }cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // memset(Map, false, sizeof(Map));
    info shark[SIZE*SIZE];

    cin>>R>>C>>M;

    int r,c;
    while(M--){
        cin>>r>>c>>Map[r][c].s>>Map[r][c].d>>Map[r][c].z;
        Map[r][c].rc = true;
        // Map[r][c].s = s;
        // Map[r][c].d = d;
        // Map[r][c].z = z;
    }

    // for(int i = 0; i < R + 1; i ++){
    //     for(int j = 0; j < C + 2; j++){
    //         cout<<Map[i][j].rc<<" ";
    //         // cout<<Map[i][j].s<<", "<<Map[i][j].d<<", "<<Map[i][j].z<<" ";
    //     }cout<<"\n";
    // }

    for(int man = 1; man < C + 2; man++){
        if(man == C + 1) break;
        huntingShark(man);
        moveShark();
    }


    cout<<sumShark<<"\n";


    return 0;
}