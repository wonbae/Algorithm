#include<bits/stdc++.h>
using namespace std;

const int idx[] = {0, 1, 0, -1};
const int idy[] = {1, 0, -1, 0};
vector<vector<int> > check;
vector<vector<int> > v;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    string str;
    
    cin>>n>>m;

    v.resize(n,vector<int>(m));
    check.resize(n,vector<int>(m));

    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < str.length(); j++){
            v[i][j] = str[j] - '0';
        }
    }

    queue<pair<int,int> > q;
    q.push({0,0});
    check[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + idx[i];
            int ny = y + idy[i];
            if(nx < 0 || ny >= m || nx >= n || ny < 0) continue;
            if(check[nx][ny]) continue; 
            if(v[nx][ny]){
                q.push({nx,ny});
                check[nx][ny] = check[x][y]+1;
            }
        }
    }

    cout<<check[n-1][m-1];
    return 0;
}