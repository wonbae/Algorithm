#include<bits/stdc++.h>
using namespace std;
#define SIZE 21

struct pos{
    int x, y;
};

// inline int min(int a, int b) {return a > b ? b : a;}

int N, A[SIZE][SIZE], district[SIZE][SIZE], ans = 987654321;
pos edge[4];

void gerrymandering(int x, int y, int d1, int d2){
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            district[i][j] = 5;
        }
    }

    int cnt = 0;
    for(int i = 0; i < edge[1].x; i++){
        if(i >= edge[0].x) cnt++;
        for(int j = 0; j <= edge[0].y - cnt; j++){
            district[i][j] = 1;
        }
    }

    int cnt2 = 0;
    for(int i = 0; i <= edge[2].x; i++){
        if(i > edge[0].x) cnt2++;
        for(int j = edge[0].y + cnt2 + 1; j < N; j++){
            district[i][j] = 2;
        }
    }

    int cnt3 = 0;
    for(int i = N - 1; i >= edge[1].x; i--){
        if(i < edge[3].x) cnt3++;
        for(int j = 0 ; j < edge[3].y - cnt3; j++){
            district[i][j] = 3;
        }
    }

    int cnt4 = 0;
    for(int i = N - 1; i > edge[2].x; i--){
        if(i <= edge[3].x) cnt4++;
        for(int j = edge[3].y + cnt4; j < N; j++){
            district[i][j] = 4;
        }
    }


    int countDistrict[6] = {0,};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            countDistrict[district[i][j]] = countDistrict[district[i][j]] + A[i][j];
        }
    }

    sort(countDistrict, countDistrict + 6);
    int tmp = countDistrict[5] - countDistrict[1];
    if(ans > tmp) ans = tmp;
}

bool boundary(int x, int y, int d1, int d2){
    // 꼭지점 경계선 1,2,3,4
    if(x + d1 >= N || y - d1 < 0) return false;
    if(x + d2 >= N || y + d2 >= N) return false;
    if(x + d1 + d2 >= N || y - d1 + d2 >= N) return false;
    if(x + d2 + d1 >= N || y + d2 - d1 < 0) return false;
    return true;
}

void setPivot(){
    for(int x = 1; x < N; x++){
        for(int y = 1; y < N; y++){
            for(int d1 = 1; d1 < y; d1++){
                for(int d2 = 1; d2 < N - y; d2++){
                    if(boundary(x, y, d1, d2)){
                        edge[0].x = x, edge[0].y = y;           //다이아몬드에서 제일 위에
                        edge[1].x = x + d1, edge[1].y = y - d1; //왼쪽
                        edge[2].x = x + d2, edge[2].y = y + d2; //오른쪽
                        edge[3].x = x + d1 + d2, edge[3].y = y - d1 + d2;   //맨 아래
                        gerrymandering(x, y, d1, d2);
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>A[i][j];
        }
    }

    setPivot();
    cout<<ans<<"\n";

    return 0;
}