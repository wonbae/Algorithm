#include<bits/stdc++.h>
using namespace std;
#define SIZE 101

int M, N;
int Map[SIZE][SIZE];
int visit[SIZE][SIZE];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>M>>N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin>>Map[i][j];
        }
    }


    return 0;
}