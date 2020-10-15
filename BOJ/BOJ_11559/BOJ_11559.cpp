#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<vector<int> > v(13, vector<int>(7, 0));
vector<vector<int> > visit(13, vector<int>(7, 0));
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans = 0;

void Print(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }
}

void Shift(){
    for(int c = 0; c < 6; c++){
        for(int r = 11; r >= 0; r--){
            if(v[r][c] == 0) continue;
            for(int k = 11; k >= r; k--){
                if(v[k][c] == 0){
                    v[k][c] = v[r][c];
                    v[r][c] = 0;
                }
            }
        }
    }
}

void Erase(vector<pair<int, int> > e){

    for(int i = 0; i < e.size(); i++){
        v[e[i].first][e[i].second] = 0;
        visit[e[i].first][e[i].second] = 0;
    }
}

void BFS(){
    int cnt = 1;
    vector<pair<int, int> > eras;
    queue<pair<int, int> > q;
    bool nothing = false;

    while(1){
        nothing = false;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(visit[i][j] == 0 && v[i][j] != 0){
                    q.push(make_pair(i, j));
                    visit[i][j] = 1;
                    cnt = 1;
                    
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        eras.push_back(make_pair(r, c));

                        for(int idx = 0; idx < 4; idx++){
                            int nr = r + dr[idx];
                            int nc = c + dc[idx];
                            if(nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
                            if(v[nr][nc] == v[r][c] && visit[nr][nc] == 0){
                                cnt++;
                                eras.push_back(make_pair(nr, nc));
                                q.push(make_pair(nr, nc));
                                visit[nr][nc] = 1;
                            }
                        }
                    }
                    
                    if(cnt >= 4){
                        Erase(eras);
                        eras.clear();
                        nothing = true;
                    }else{
                        eras.clear();
                        for(int i = 0; i < 12; i++){
                            for(int j = 0; j < 6; j++){
                                visit[i][j] = 0;
                            }
                        }
                    }
                }
            }
        }
        if(nothing){
            ans++;
            Shift();
        }
        else{
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char input;
    
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin>>input;
            if(input == '.'){
                v[i][j] = 0;
            }else if(input == 'R'){
                v[i][j] = 1;
            }else if(input == 'G'){
                v[i][j] = 2;
            }else if(input == 'B'){
                v[i][j] = 3;
            }else if(input == 'P'){
                v[i][j] = 4;
            }else if(input == 'Y'){
                v[i][j] = 5;
            }
        }
    }

    BFS();
    cout<<ans<<"\n";
    return 0;
}