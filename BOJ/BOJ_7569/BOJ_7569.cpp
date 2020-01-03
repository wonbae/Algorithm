#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int tomato[MAX][MAX][MAX] = {0,};
bool visit[MAX][MAX][MAX] = {false,};
int M,N,H;

void PRINT(){
    cout<<"\n====== Print Tomato =======\n";
    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cout<<tomato[y][x][z]<<" ";
            }cout<<"\n";
        }cout<<"\n";
    }
}

int main(){    
    queue<pair<int, int> > q;
    
    cin>>M>>N>>H;

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                cin>>tomato[y][x][z];
            }
        }
    }

    PRINT();

    for(int z = 0; z < H; z++){
        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                if((tomato[y][x][z] = 1) && (visit[y][x][z] = false)){
                    q.push(make_pair(y,x));
                    
                }
            }
        }
    }

    return 0;
}