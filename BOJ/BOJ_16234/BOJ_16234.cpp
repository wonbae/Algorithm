#include<bits/stdc++.h>
using namespace std;

#define SIZE 50

int N, L, R;
int nation[SIZE][SIZE];
int isUnion[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int day, divide;

bool open(int a, int b){
    if(abs(a - b) >= L && abs(a - b) <= R){
        return true;
    }
    return false;
}

void migrate(int div){
    cout<<"div : "<<div<<"\n";

    for(int d = 1; d < div; d++){
        int psum = 0;
        int pcnt = 0;

        cout<<"\n==== Before Union =====\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<nation[i][j]<<" ";
            }cout<<"\n";
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(isUnion[i][j] == d){
                    psum += nation[i][j];
                    pcnt++;
                }
            }
        }

        int res = int(psum / pcnt);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(isUnion[i][j] == d){
                    nation[i][j] = res;
                }
            }
        }
        cout<<"\n==== After Union =====\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<nation[i][j]<<" ";
            }cout<<"\n";
        }
    }

    day += 1;
    memset(isUnion, 0, sizeof(isUnion));
    
}

bool Border(){
    memset(isUnion, 0, sizeof(isUnion));
    bool flag = false;
    divide = 0;
    queue<pair<int, int> > q;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(isUnion[i][j] < 0){
                q.push(make_pair(i, j));
                divide += 1;
                cout<<"divide : "<<divide<<", "<<"\n";

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(isUnion[nx][ny] >= 0) continue;

                        if(open(nation[nx][ny], nation[x][y])){
                            flag = true;
                            isUnion[nx][ny] = divide;
                            isUnion[x][y] = divide;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }

    if(flag){
        migrate(divide);
    }else{
        return true;
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin>>N>>L>>R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>nation[i][j];
        }
    }

    while(1){
        bool a = Border();
        if(a){
            break;
        }
    }

    cout<<day<<"\n";

    return 0;
}