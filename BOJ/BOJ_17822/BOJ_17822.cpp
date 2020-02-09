#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int N, M, T;
int x, d, k;
int circle[SIZE][SIZE];
bool visit[SIZE][SIZE];
bool eraseCheck[SIZE][SIZE];
bool flag = true;

void printCircle(){
    cout<<"\n";
    cout<<"\n"<<"++++++ Circle +++++++"<<"\n";

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout<<circle[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void initialize(){
    memset(circle, 0, sizeof(circle));
    memset(visit, false, sizeof(visit));
    memset(eraseCheck, false, sizeof(eraseCheck));

    cin>>N>>M>>T;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>circle[i][j];
        }
    }

}

void rotation(){
    int tmp[SIZE];
    int kk = k % M;
    
    if(d){  //반시계 d=1
        for(int j = 0; j < N; j++){
            if((j + 1) % x == 0){
                int idx = 0;
                for(int i = 0; i < M; i++){
                    if(i < kk){
                        tmp[M - kk + i] = circle[j][i];
                    }else{
                        tmp[i - kk] = circle[j][i];
                    }
                }

                for(int i = 0; i < M; i++){
                    circle[j][i] = tmp[i];
                }
            }
        }
        
    }
    else{   //시계방향 d = 0
        int a = M - kk;
        for(int j = 0; j < N; j++){
            if((j + 1) % x == 0){
                int idx = 0;
                for(int i = 0; i < M; i++){
                    if(i >= a){
                        tmp[idx++] = circle[j][i];
                    }
                }
                for(int i = 0; i < a; i++){
                    tmp[idx++] = circle[j][i];
                }

                for(int i = 0; i < M; i++){
                    circle[j][i] = tmp[i];
                }

            }
        }
        
    }

}

void eraseCircle(){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(eraseCheck[i][j] && circle[i][j] != 0){
                circle[i][j] = 0;
                flag = false;
            }
        }
    }
}

void adjacency(){

    memset(visit, false, sizeof(visit));
    memset(eraseCheck, false, sizeof(eraseCheck));

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    queue<pair<int, int> > q;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            if(visit[i][j] == true || circle[i][j] == 0){
                continue;
            }

            q.push(make_pair(i,j));
            visit[i][j] = true;     //방문했으니깐 true

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int idx = 0; idx < 4; idx++){
                    int nx = x + dx[idx];
                    int ny = y + dy[idx];
                    nx %= N; 
                    ny %= M;

                    if(nx < N && nx >= 0 && ny < M && ny >= 0){
                        if(circle[x][y] == circle[nx][ny] && visit[nx][ny] == false && circle[nx][ny] != 0){
                            q.push(make_pair(nx,ny));
                            visit[nx][ny] = true;
                            eraseCheck[x][y] = true;
                            eraseCheck[nx][ny] = true;
                            
                        }

                    }else{
                        continue;
                    }
                }
            }
        }
    }

    eraseCircle();

}

void avgPlusMinus(){

    int sum = 0, cnt = 0;

    for(int i = 0; i < N;i ++){
        for(int j = 0; j < M; j++){
            if(circle[i][j] != 0){
                sum += circle[i][j];
                cnt++;
            }
        }
    }

    double avg = double(sum) / double(cnt);

    for(int i = 0; i < N;i ++){
        for(int j = 0; j < M; j++){
            if(circle[i][j] != 0){
                if(circle[i][j] > avg){
                    circle[i][j] -= 1;
                }else if(circle[i][j] < avg){
                    circle[i][j] += 1;
                }
            }
        }
    }
}

int Sum(){
    int answer = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(circle[i][j] != 0){
                answer += circle[i][j];
            }
        }
    }

    return answer;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    initialize();        //원판값 받기 + 회전명령 받기

    for(int i = 0; i < T; i++){
        flag = true;
        cin>>x>>d>>k;

        rotation();     //명령에 따라 원판 돌리기
        adjacency();    //인접값 BFS로 찾아 없애기

        if(flag){
            avgPlusMinus(); //평균구해서 작으면 더하고 크면 빼기
        }

        // printCircle();
        
    }
    
    cout<<Sum()<<"\n";

    return 0;
}