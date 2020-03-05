#include<bits/stdc++.h>
using namespace std;

#define SIZE 51

inline int abs(int nx, int x, int ny, int y){
    int x_tmp = nx > x ? (nx - x) : (x - nx);
    int y_tmp = ny > y ? (ny - y) : (y - ny);
    return x_tmp + y_tmp;
}

inline int min(int a, int b){
    return a > b ? b : a;
}

int City[SIZE][SIZE] = {0,};
int Visit[SIZE][SIZE] = {0,};
int Check[SIZE][SIZE] = {0,};
int N, M;   //N <= 50, M <= 13


void PRINT(){
    cout<<"\n====== Check =========\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<Check[i][j];
        }cout<<"\n";
    }
}

void solution(){
    




}

bool desc(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> ans;

    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>City[i][j];
            if(City[i][j] == 1) Visit[i][j] = 1;    //home
            if(City[i][j] == 2) Visit[i][j] = 2;    //chicken
        }
    }

    solution();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Check[i][j] != 0){
                ans.push_back(Check[i][j]);
            }
        }
    }

    sort(ans.begin(), ans.end(), desc);

    int result = 0;
    for(int i = 0; i < M; i++){
        result += ans[i];
    }

    cout<<result<<"\n";

    return 0;
}