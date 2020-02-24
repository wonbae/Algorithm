#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int Map[MAX][MAX] = {0,};
int Visit[MAX][MAX] = {0,};
int col, raw;

bool iszero(){

    int res = true;
    for(int i = 0; i < raw; i++){
        for(int j = 0; j < col; j++){
            if(Visit[i][j] == 0){
                return false;
            }
        }
    }

    return res;
}

int BFS(){
    int cnt = -2;

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    queue<pair<int, int> > q;

    for(int i = 0; i < raw; i++){
        for(int j = 0; j < col; j++){
            if(Map[i][j] == 1 && Visit[i][j] == 0){
                q.push(make_pair(i,j));
                Visit[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

                    // cout<<"\n=== Map  ====\n";
                    // for(int i = 0; i < raw; i++){
                    //     for(int j = 0; j < col; j++){
                    //         cout<<Map[i][j]<<" ";
                    //     }cout<<"\n";
                    // }

        for(int idx = 0; idx < 4; idx++){
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if(nx >= 0 && nx < raw && ny >= 0 && ny < col && Map[nx][ny] != -1){
                if(Visit[nx][ny] == 0 && Map[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    Map[nx][ny] = Map[x][y] + 1;
                    Visit[nx][ny] = 1;
                }
            }
        }
                    
    }
            

    if(iszero()){
        for(int i = 0; i < raw; i++){
            for(int j = 0; j < col; j++){
                cnt = max(Map[i][j], cnt);
            }
        }
    }else{
        return -1;
    }

    return cnt - 1;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin>>col>>raw;

    for(int i = 0; i < raw; i++){
        for(int j = 0; j < col; j++){
            cin>>Map[i][j];
            if(Map[i][j] == -1){
                Visit[i][j] = -1;
            }
        }
    }

    cout<<BFS()<<"\n";


    return 0;
}