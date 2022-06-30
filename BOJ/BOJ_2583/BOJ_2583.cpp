#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v;
vector<vector<int> > check;
vector<int> ans;
int m, n, cnt;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int x, int y){
    check[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(check[nx][ny] == 0 && v[nx][ny] == 0){
            cnt++;
            dfs(nx,ny);
        }
    }
    return ;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int k;
    cin>>m>>n>>k;

    v.resize(m, vector<int>(n,0));
    check.resize(m, vector<int>(n,0));
    

    for(int i = 0; i < k; i++){
        int lx, ly, rx, ry;
        cin>>lx>>ly>>rx>>ry;
        for(int i = ly; i < ry; i++){
            for(int j = lx; j < rx; j++){
                v[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j] == 0 && v[i][j] == 0){
                cnt = 1;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    cout<<ans.size()<<"\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}