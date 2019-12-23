#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int Map[MAX][MAX] = {0,};
int visit[MAX][MAX] = {0,};
int M, N;
int K;


// void initmap(int lx, int ly, int rx, int ry){
//     // M is x axis, N is y axis;
//     int cnt = 0;
//     for(int y = ly; y < ry; y++){
//         for(int x = lx; x < rx; x++){
//             Map[y][x] = 1;
//         }
//     }
// }

void init() {
    int x1, x2, y1, y2;

    while(K--){
        cin>>x1>>y1>>x2>>y2;

        for(int i = x1; i < x2; i++)
            for(int j = y1; j < y2; j++)
                Map[j][i]=1;
    }
    
}

int main(){
    

    cin>>M>>N>>K;

    init();

    // for(int i = 0; i < K; i++){
    //     int lx,ly,rx,ry;
    //     cin>>lx>>ly>>rx>>ry;
    //     initmap(lx, ly, rx, ry);
    // }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
        {
            cout<<Map[i][j];
        }cout<<"\n";
    }
            
    return 0;
}