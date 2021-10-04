#include<iostream>
#include<vector>

using namespace std;

int n, m, cnt = 0, pr, pc, first_dir;
vector<vector<char> > vec;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int P[] = {1, 0, 3, 2};
int Q[] = {3, 2, 1, 0};
char direction[] = {'U', 'R', 'D', 'L'}, ans_dir;
bool finish=false;

void dfs(int r, int c, int dir){
    if(r < 0 || r >= n || c < 0 || c >= m){
        return ;
    }
    if(vec[r][c] == 'C'){
        return ;
    }
    if(cnt!=0 && r == pr-1 && c == pc-1 && dir == first_dir){
        cout<<direction[dir]<<"\nVoyager\n";
        finish = true;
        return ;
    }

    if(vec[r][c] == '/'){
        cnt++;
        // cout<<cnt<<"\n";
        dir = P[dir];
        dfs(r+dr[dir], c+dc[dir], dir);
    }
    else if(vec[r][c] == '\\'){
        cnt++;
        // cout<<cnt<<"\n";
        dir = Q[dir];
        dfs(r+dr[dir], c+dc[dir], dir);
    }
    else if(vec[r][c] == '.'){
        cnt++;
        // cout<<cnt<<"\n";
        dfs(r+dr[dir], c+dc[dir], dir);
    }
    return ;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    int ans=0;

    cin>>n>>m;
    vec.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>vec[i][j];
        }
    }
    cin>>pr>>pc;

    for(int i = 0; i < 4; i++){
        cnt = 0;
        first_dir = i;

        dfs(pr-1,pc-1,i);
        if(finish){
            return 0;
        }
        if(ans < cnt){
            ans = cnt;
            ans_dir = direction[i];
        }
    }
    cout<<ans_dir<<"\n"<<ans;

    return 0;
}