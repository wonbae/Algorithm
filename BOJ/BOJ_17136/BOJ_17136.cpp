#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

vector<vector<int> > dp(11, vector<int>(11, 0));
vector<int> remain(6, 5);
int paperCount;
int MINI = 987654321;

bool isCheck(int r, int c, int size){
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            if(dp[i][j] == 0) return false;
        }
    }
    return true;
}


void putPaper(int r, int c, int size){
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            dp[i][j] = 0;
        }
    }
    return ;
}


void removePaper(int r, int c, int size){
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            dp[i][j] = 1;
        }
    }
    return ;
}


void dfs(int depth, int nr, int paperCnt){
    if(MINI < depth) return;

    if(paperCnt == 0){
        if(MINI > depth) {
            MINI = depth;
        }
        return;
    }

    for(int r = nr; r < 10; r++){
        for(int c = 0; c < 10; c++){
            if(dp[r][c] == 0) continue;

            for(int rec = 5; rec >= 1; rec--){

                if(remain[rec] == 0) continue;

                if(r + rec > 10 || c + rec > 10) continue;

                if(isCheck(r, c, rec)){
                    remain[rec]--;
                    putPaper(r, c, rec);
                    
                    dfs(depth + 1, r, paperCnt - (rec *  rec));

                    remain[rec]++;
                    removePaper(r, c, rec);
                }
            }

            return;
        }
    }

    return ;
}

int main(){
    fastio;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin>>dp[i][j];

            paperCount+=dp[i][j];
        }
    }

    for(int i = 1; i <= 5; i++){
        remain[i] = 5;
    }

    // cout<<"\n == DP == "<<"\n";
    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }cout<<"\n";

    
    dfs(0, 0, paperCount);
    

    if(MINI == 987654321) cout<<"-1"<<"\n";
    else cout<<MINI<<"\n";

    return 0;
}