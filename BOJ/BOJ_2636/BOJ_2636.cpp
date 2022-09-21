#include<bits/stdc++.h>
using namespace std;

int N,M;
int v[101][101];
int visited[101][101];
vector<pair<int,int> > erase_ch;
int total,cnt;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int r, int c){
    visited[r][c] = 1;
    if(v[r][c] == 1){
        erase_ch.push_back({r,c});
        return ;
    }

    for(int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(r >= N || c >= M || r < 0 || c < 0 || visited[nr][nc]) continue;
        
        dfs(nr,nc);
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>v[i][j];
        }
    }

    while(true){
        total++;
        cnt = 0;
        
        //check near 0
        fill(&visited[0][0], &visited[0][0]+101*101, 0);
        erase_ch.clear();

        dfs(0,0);
       
        //erase
        for(int i = 0; i < erase_ch.size(); i++){
            cnt++;
            v[erase_ch[i].first][erase_ch[i].second] = 0;
        }

        //count rest of cheese
        bool flag=false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(v[i][j] != 0) flag=true;
            }
        }

        if(!flag) break;
    }

    cout<<total<<"\n"<<cnt<<"\n";
    return 0;
}