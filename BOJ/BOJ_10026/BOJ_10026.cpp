#include<bits/stdc++.h>
using namespace std;


int RGB_map[101][101] = {0,};
int comb_map[101][101] = {0,};  //combined map

int visit[101][101] = {0,};
int visit2[101][101] = {0,};

void init(int i, int j, char c){
    if(c == 'R'){
        RGB_map[i][j] = 1;
        comb_map[i][j] = 1;

    }else if(c == 'G'){
        RGB_map[i][j] = 2;
        comb_map[i][j] = 1;

    }else if(c == 'B'){
        RGB_map[i][j] = 3;
        comb_map[i][j] = 2;
    }


}

int BFS(int N){
    int count = 0;
    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visit[i][j] == 0){
                q.push(make_pair(i,j));
                visit[i][j] = 1;
                count++;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx >= N && nx < 0 && ny >= N && ny < 0 && visit[nx][ny] == 1){
                            continue;
                        }

                        if(RGB_map[x][y] == RGB_map[nx][ny] && visit[nx][ny] == 0){
                            q.push(make_pair(nx,ny));
                            visit[nx][ny] = 1;
                        }
                        
                    }
                }
            }
        }
    }

    

    return count;
}   

int c_BFS(int N){
    int count = 0;
    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visit2[i][j] == 0){
                q.push(make_pair(i,j));
                visit2[i][j] = 1;
                count++;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx > N && nx < 0 && ny > N && ny < 0 && visit2[nx][ny] == 1){
                            continue;
                        }

                        if(comb_map[x][y] == comb_map[nx][ny]&& visit2[nx][ny] == 0){
                            q.push(make_pair(nx,ny));
                            visit2[nx][ny] = 1;
                        }
                        
                    }
                }
            }
        }
    }

    return count;
}
void print_map(int N){
    cout<<"\n++++++++++RGB_map Print++++++++++\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<RGB_map[i][j];
        }cout<<"\n";
    }

    cout<<"\n++++++++++comb_map Print++++++++++\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<comb_map[i][j];
        }cout<<"\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin>>N;
    char input;

    //input
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>input;
            init(i, j, input);
        }
    }
    // print_map(N);

    int rgb = BFS(N);
    int cb = c_BFS(N);

    cout<<rgb<<" "<<cb<<"\n";

    return 0;
}