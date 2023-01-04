#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int x,y,d,g;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
vector<int> v[4][11];
int a[101][101];

void init(){
    for(int i = 0; i < 4; i++){
        v[i][0].push_back(i);
        v[i][1].push_back((i+1)%4);
        for(int j = 2; j <= 10; j++){
            int n = v[i][j-1].size();
            for(int k = n-1; k >= 0; k--){
                v[i][j].push_back((v[i][j-1][k]+1)%4);
            }
            for(int k = 0; k < n; k++){
                v[i][j].push_back(v[i][j-1][k]);
            }
        }
    }
    return ;
}

void curve(int x, int y, int d, int g){
    int _x = x;
    int _y = y;
    a[_x][_y]=1;
    for(int i = 0; i <= g; i++){
        for(int dir : v[d][i]){
            _x += dx[dir];
            _y += dy[dir];
            a[_x][_y] = 1;
        }
    }    
    return ;
}

int main(){
    fastio;
    int n, cnt=0;
    cin>>n;
    init();
    for(int i = 0; i < n; i++){
        cin>>x>>y>>d>>g;
        curve(x,y,d,g);
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) cnt++;
        }
    }

    cout<<cnt<<"\n";
    return 0;
}