#include<bits/stdc++.h>
using namespace std;
#define SIZE 20

int Map[SIZE][SIZE];
bool isCombi[SIZE];
int N;
int MIN = 987654321;

void teamBalance(){
    int tmp = 0, score = 0, lscore = 0, sscore = 0;
    vector<int> lteam;
    vector<int> steam;

    for(int i = 0; i < N; i++){
        if(isCombi[i]){
            steam.push_back(i);
        }else{
            lteam.push_back(i);
        }
    }

    int len = steam.size();     // steam, lteam 둘다 사이즈 같음
    for(int i = 0; i < len ; i++){
        for(int j = 0; j < len; j++){
            if(i == j) continue;
            lscore += Map[lteam[i]][lteam[j]];
            sscore += Map[steam[i]][steam[j]];
        }
    }

    tmp = abs(lscore - sscore);
    MIN = tmp < MIN ? tmp : MIN;
    return;
}

void nCr(int n, int r){
    if(r == N/2){
        teamBalance();
        return;
    }
    
    for(int i = n; i < N; i++){
        if(isCombi[i]) continue;

        isCombi[i] = true;
        nCr(i + 1, r + 1);
        isCombi[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>Map[i][j];
        }
    }

    memset(isCombi, false, sizeof(isCombi));
    isCombi[0] = true;
    nCr(1, 1);

    cout<<MIN<<"\n";

    return 0;
}