#include<bits/stdc++.h>
using namespace std;

    int T,N;
    int st_x, st_y;
    int end_x, end_y;
    vector<vector<int> > chess_map;
   
void BFS(){ 

    int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    queue<pair<int, int> > q;

    q.push(make_pair(st_x, st_y)); 
    chess_map[st_x][st_y] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cout<<"\n====== Print =======\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<chess_map[i][j]<<" ";
            }cout<<endl;
        }
        for(int idx = 0; idx < 8; idx++){
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(chess_map[nx][ny] == -1){
                    q.push(make_pair(nx,ny));
                    chess_map[nx][ny] = chess_map[x][y] + 1;

                    if(nx == end_x && ny == end_y){
                        return ;
                    }
                }
                
            }
        }
    }
   

}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin>>T;

    while(T--){
        cin>>N;
        cin>>st_x>>st_y>>end_x>>end_y;

        chess_map = vector<vector<int> > (N, vector<int>  (N, -1));

        BFS();

        cout<<chess_map[end_x][end_y]<<"\n";


    }


    return 0;
}

  