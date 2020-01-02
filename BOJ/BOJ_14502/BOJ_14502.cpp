// 어렵넴.. 순열조합 공부하고 다시풀자
#include<bits/stdc++.h>
using namespace std;

#define MAX 8

int Map[MAX][MAX] = {0,};
int visit[MAX][MAX] = {0,};
int N, M;

int main(){
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>Map[i][j];
            if(Map[i][j] == 1){
                visit[i][j] = 1;
            }
        }
    }



    return 0;
}