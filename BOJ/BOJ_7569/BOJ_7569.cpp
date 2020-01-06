#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int tomato[MAX][MAX][MAX] = {0,};
bool visit[MAX][MAX][MAX] = {false,};
int M,N,H;

typedef struct TOMA{
    int y,x,z;

    TOMA(int y, int x, int z) : y(y), x(x), z(z)
    {

    }

}TOMA;

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
    queue<TOMA> Q;
    
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
                if(tomato[y][x][z] == 1){
                    Q.push(TOMA(y,x,z));
                
                    while(!Q.empty()){
                        int y = Q.front().y;
                        int x = Q.front().x;
                        int z = Q.front().z;
                        Q.pop();

                        cout<<"y : "<<y<<", x : "<<x<<", z : "<<z<<"\n";

                    }
                }
            }
        }
    }


    return 0;
}