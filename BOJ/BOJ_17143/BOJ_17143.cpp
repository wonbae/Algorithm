#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

struct info{
    int s, d, z;    // 상어의 속도, 방향, 크기
};

info Map[SIZE + 1][SIZE + 2];
int R,C,M;
int sumShark;
const int dx[] = {-1, 1, 0, 0};     //d : 1 위, 2 아래, 3 우, 4 좌
const int dy[] = {0, 0, 1, -1};

void fishingShark(int col){
    for(int r = 1; r <= R; r++){
        if(Map[r][col].z){
            sumShark += Map[r][col].z;
            // cout<<"Fishging : "<<Map[r][col].z<<"\n";
            Map[r][col].s = 0;
            Map[r][col].d = 0;
            Map[r][col].z = 0;
            break;
        }
    }
}

void moveShark(){
    info copy[SIZE + 1][SIZE + 2] = {0};

    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            if(Map[r][c].z){   //z가 있다는건 상어를 움직여야함
                int s = 0;
                int d = Map[r][c].d;
                int new_r = r;
                int new_c = c;

                if(d == 1 || d == 2){       //위 아래
                    s = Map[r][c].s % ((R - 1) * 2);

                    while(s--){
                        if(new_r == 1 && d == 1) d = 2;     //위면 아래로
                        if(new_r == R && d == 2) d = 1;     //아래면 위로
                        new_r += dx[d - 1];
                    }
                    
                    if(Map[r][c].z > copy[new_r][c].z){      // 옮길려고 하는 상어 크기 > 원래 있던 상어 크기
                        copy[new_r][c].s = Map[r][c].s;
                        copy[new_r][c].d = d;
                        copy[new_r][c].z = Map[r][c].z;
                    }
                    
                }else{      // 좌 우
                    s = Map[r][c].s % ((C - 1) * 2);

                    while(s--){
                        if(new_c == 1 && d == 4) d = 3;
                        if(new_c == C && d == 3) d = 4;
                        new_c += dy[d - 1];
                    }

                    if(Map[r][c].z > copy[r][new_c].z){
                        copy[r][new_c].s = Map[r][c].s;
                        copy[r][new_c].d = d;
                        copy[r][new_c].z = Map[r][c].z;
                    }
                }
                Map[r][c].s = 0, Map[r][c].d = 0, Map[r][c].z = 0;
            }
        }
    }
    memcpy(Map, copy, sizeof(copy));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>R>>C>>M;

    int r,c;
    while(M--){
        cin>>r>>c>>Map[r][c].s>>Map[r][c].d>>Map[r][c].z;
        // Map[r][c].s = s;
        // Map[r][c].d = d;
        // Map[r][c].z = z;
    }

    for(int man = 1; man <= C; man++){
        if(man == C + 1) break;
        fishingShark(man);
        moveShark();
    }

    cout<<sumShark<<"\n";

    return 0;
}