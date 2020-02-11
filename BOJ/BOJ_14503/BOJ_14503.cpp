#include<bits/stdc++.h>
using namespace std;
#define SIZE 50

int N, M;
int r, c, d;
int cSpace[SIZE][SIZE];         //Search Space
bool cleanHere[SIZE][SIZE];     //visit

void initialize(){
    // memset(cSpace, 0, sizeof(cSpace));
    memset(cleanHere, false, sizeof(cleanHere));

    cin>>N>>M;
    cin>>r>>c>>d;       //row, col, direction

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>cSpace[i][j];          //빈칸은 0, 벽은 1
        }
    }

}

int cleaning(){
    int cnt = 0;
    queue<pair<int, int> > q;
    int dx[] = {};
    int dy[] = {};
    
    q.push(make_pair(r,c));
    cleanHere[r][c] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    initialize();
    answer = cleaning();

    cout<<answer<<"\n";

    return 0;
}