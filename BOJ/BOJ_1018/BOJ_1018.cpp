#include<bits/stdc++.h>
using namespace std;
#define SIZE 51

int chese[SIZE][SIZE];

int fun(int r, int c, bool flag){
    int res = 0;
    for(int i = r; i < r + 8; i++){
        for(int j = c; j < c + 8; j++){
            if(j % 2 == 0 && chese[i][j] != flag) res++;
            else if(j % 2 == 1 && chese[i][j] == flag) res++;
        }
        flag = !flag;
    }
    return res;
}

int main(){
    int M, N;
    cin>>M>>N;

    string str = "";
    cin.ignore(256, '\n');

    for(int i = 0; i < M; i++){
        getline(cin, str);
        for(int j = 0; j < N; j++){
            if(str[j] == 'W') chese[i][j] = 0;
            else chese[i][j] = 1;
        }
    }
    
    int cnt = 987654321;
    for(int i = 0; i <= M - 8; i++){
        for(int j = 0; j <= N - 8; j++){
            cnt = min(cnt, fun(i, j, 0));
            cnt = min(cnt, fun(i, j, 1));
            
        }
    }

    cout<<cnt<<"\n";

    return 0;
}