#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int N, M;
int r, c, d;
int cSpace[SIZE][SIZE];         //Search Space
int cleanHere[SIZE][SIZE];     //visit

void initialize(){
    // memset(cSpace, 0, sizeof(cSpace));
    memset(cleanHere, 0, sizeof(cleanHere));

    cin>>N>>M;
    cin>>r>>c>>d;       //row, col, direction

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>cSpace[i][j];          // 미방문 0, 벽 1, 방문 2
            if(cSpace[i][j] == 1) cleanHere[i][j] = 1;
        }
    }

}

int cleaning(){
    int cnt = 0;
    int dx[] = {-1, 0, 1, 0};   //서 -> 남 -> 동 -> 북 (반시계방향)
    int dy[] = {0, -1, 0, 1};
    
    while(1){
        
    }
    






    int res = 0;
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            if(cleanHere[i][j] == 2){
                res++;
            }
        }
    }

    return res;
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