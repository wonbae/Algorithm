#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int map[999][999];
    int N, insert_num, find_num;
    bool flag = false;

    int dx[] = {1, 0, -1, 0};   // dx,dy Right - Down - Left - Up
    int dy[] = {0, 1, 0, -1};

    cin>>N>>find_num;

    // memset(map, 0, sizeof(map));
    int start_num = N * N;
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            map[i][j] = start_num; // N * N
        }
    }

    return 0;
}