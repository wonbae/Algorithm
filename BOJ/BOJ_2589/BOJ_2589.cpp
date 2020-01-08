// 92ms이다 다른사람 0ms, 4ms 소스 읽어보자..

#include<bits/stdc++.h>
using namespace std;

#define MAX 50

int Map[MAX][MAX] = {0,};
int visit[MAX][MAX] = {0,};
int check[MAX][MAX] = {0,};
int row, col;

int BFS(){
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int hour = 0;
    queue<pair<int, int> > q;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(Map[i][j] == 0){

                memset(visit, 0, sizeof(visit));
                memset(check, 0, sizeof(check));

                q.push(make_pair(i,j));
                visit[i][j] = 1;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

                        if(Map[nx][ny] == 1 || visit[nx][ny] == 1) continue;

                        q.push(make_pair(nx,ny));
                        visit[nx][ny] = 1;
                        check[nx][ny] = check[x][y] + 1;
                        hour = max(check[nx][ny], hour);
                    }
                }
                
            }
            
        }
    }
    return hour;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string input;

    cin>>row>>col;

    for(int i = 0; i < row; i++){
        cin>>input;
        int len = input.length();
        for(int j = 0; j < len; j++){
            if(input[j] == 'L'){
                Map[i][j] = 0;
            }else if(input[j] == 'W'){
                Map[i][j] = 1;
                visit[i][j] = 1;
                // check[i][j] = 1;
            }
        }
    }
    
    cout<<BFS()<<"\n";

    

    return 0;
}