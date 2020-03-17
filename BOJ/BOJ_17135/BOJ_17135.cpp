// boj_17135 Castle Defense G4
#include<bits/stdc++.h>
using namespace std;
#define SIZE 15

int N, M, D;
int Map[SIZE][SIZE];
int tmp[SIZE][SIZE];
bool visit[SIZE][SIZE];
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int answer, ecnt;

int dist(int nx, int ny, int x, int y){
    return abs(nx - x) + abs(ny - y);
}

void kill(){
    cout<<"\n++++++++ kill start ++++++++\n";
    memcpy(tmp, Map, sizeof(Map));
    ecnt = 0;
    int term = N;
    vector<pair<int, int> > archer;
    vector<pair<int, int> > enermy;

    cout<<"\n";
    cout<<"answer : "<<answer<<"\n";
    for(int r = 0; r <= N; r++){
        for(int c = 0; c < M; c++){
            cout<<tmp[r][c]<<" ";
        }cout<<"\n";
    }
    
    while(term){
        for(int c = 0; c < M; c++){
            if(Map[term][c] == 2)
                archer.push_back(make_pair(term, c));
        }    
 
        for(int i = 0; i < 3; i++){
            int shortest = 987654321, a = 0, b = 0;
            for(int r = term - 1; r >= 0; r--){
                for(int c = 0; c < M; c++){
                    if(tmp[r][c] == 0) continue;
                    if(tmp[r][c] == 1){
                        int x = archer[i].first;
                        int y = archer[i].second;

                        if(dist(x, y, r, c) <= D){
                            shortest = min(shortest, dist(x, y, r, c)); 
                            enermy.push_back(make_pair(a, b));
                        }else continue;
                    }
                }
            }
            
        }

        for(int i = 0; i < enermy.size(); i++){
            cout<<"("<<enermy[i].first<<", "<<enermy[i].second<<")\n";
            ecnt++;
            tmp[enermy[i].first][enermy[i].second] = 0;
        }

        // cout<<"\n";
        // cout<<"answer : "<<answer<<"\n";
        // for(int r = 0; r <= N; r++){
        //     for(int c = 0; c < M; c++){
        //         cout<<tmp[r][c]<<" ";
        //     }cout<<"\n";
        // }
        
        for(int c = 0; c < M; c++){
            if(term - 1 < 0) break;
            tmp[term - 1][c] = 0;
            tmp[term - 1][c] = tmp[term][c];
            tmp[term][c] = 0;
        }

        if(answer < ecnt) answer = ecnt;
        term--;
        archer.clear();
    }
}

void nCrArcher(int col, int cnt){
    if(cnt == 3){
        // for(int i = 0; i < M; i++){
        //     cout<<Map[N][i]<<" ";
        // }
        // cout<<"\n";
        kill();
        return;
    }

    for(int i = col; i < M; i++){
        if(Map[N][i] == 2) continue;

        Map[N][i] = 2;
        nCrArcher(col + 1, cnt + 1);
        Map[N][i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M>>D;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>Map[i][j]; 
        }
    }

    nCrArcher(0, 0);

    cout<<answer<<"\n";

    return 0;
}

