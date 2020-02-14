#include<bits/stdc++.h>
using namespace std;
#define SIZE 100

int land[SIZE][SIZE];
bool sink[SIZE][SIZE];
int N;

int MAX(int a, int b){
    return a > b ? a : b;
} 

void Input(){
    cin>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>land[i][j];
        }
    }

}

void initialize(int h){
    memset(sink, false, sizeof(sink)); 

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(land[i][j] <= h) sink[i][j] = true;
        }
    }
}

int safeland(int h){     //BFS
    int count = 0;
    queue<pair<int, int> > q;
    int dx[] = {-1, 0, 1, 0};      //시계방향
    int dy[] = {0, 1, 0, -1};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!sink[i][j] && land[i][j] > h){
                q.push(make_pair(i,j));
                sink[i][j] = true;
                count++;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int idx = 0; idx < 4; idx++){
                        int nx = x + dx[idx];
                        int ny = y + dy[idx];

                        if(nx < N && nx >= 0 && ny < N && ny >= 0){
                            if(land[nx][ny] > h && !sink[nx][ny]){
                                q.push(make_pair(nx,ny));
                                sink[nx][ny] = true;
                            }
                            
                        }else continue;
                    }
                }
            }else continue;
        }
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int res = 0;
    int maximum = 1;

    Input();
    
    for(int h = 1; h <= 100; h++){
        
        initialize(h);
        maximum = MAX(maximum,safeland(h));
        res = maximum;
    }
    
    cout<<res<<"\n";

    return 0;
}