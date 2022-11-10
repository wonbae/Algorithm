#include<bits/stdc++.h>
using namespace std;

int r,c;
vector<pair<int, int> > delvec;
char lake[1502][1502];
int visited[1502][1502];
int checked[1502][1502];
int meeting[1502][1502];
vector<pair<int, int> > birld;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void searchIce(int x, int y){
    queue<pair<int, int> > q;

    q.push({x,y});
    checked[x][y] = 1;

    while(!q.empty()){
        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_r = now_r + dx[i];
            int next_c = now_c + dy[i];
            if(lake[next_r][next_c] == 'L' || checked[next_r][next_c] || next_r < 0 || next_r >= r || next_c < 0 || next_c > c) continue;
            if(lake[next_r][next_c] == 'X'){
                delvec.push_back({next_r, next_c});
                checked[next_r][next_c] = 1;
                continue;
            }
            if(lake[next_r][next_c] == '.'){
                q.push({next_r, next_c});
                checked[next_r][next_c] = 1;
            }
        }
    }

}

void meltingIce(){
    for(int i = 0; i < delvec.size(); i++){
        int rr = delvec[i].first;
        int cc = delvec[i].second;

        lake[rr][cc] = '.';
    }
}

bool canMeet(){
   queue<pair<int, int> > q;

    int stx = birld[0].first;
    int sty = birld[0].second;

    q.push({stx, sty});
    meeting[stx][sty] = 1;

    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nxx = xx + dx[i];
            int nyy = yy + dy[i];

            if(lake[nxx][nyy] == 'X' || meeting[nxx][nyy] || nxx < 0 || nxx > r || nyy < 0 || nyy > c) continue;
            if(lake[nxx][nyy] == 'L'){
                return true;
            }
            if(lake[nxx][nyy] == '.'){
                meeting[nxx][nyy]=1;
                q.push({nxx,nyy});
            }
            
        }

    }

    return false;

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    cin>>r>>c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin>>lake[i][j];
            if(lake[i][j] == 'L'){
                birld.push_back({i,j});
            }
        }
    }

    int day = 0;
    
    while(!canMeet()){
        memset(visited, 0, sizeof(visited));
        memset(checked, 0, sizeof(checked));
        memset(meeting, 0, sizeof(meeting));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(lake[i][j] == '.' && visited[i][j] == 0){
                    searchIce(i,j);
                }
            }
        }

        meltingIce();

        day++;
    }

    cout<<day<<"\n";

    return 0;
}
