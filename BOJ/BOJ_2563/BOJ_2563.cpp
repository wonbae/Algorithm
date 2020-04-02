#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, cnt = 0, board[101][101] = {0,};
    cin>>T;

    while(T--){
        int x, y;
        cin>>x>>y;

        for(int r = y; r < y + 10; r++){
            for(int c = x; c < x + 10; c++){
                cnt += !board[r][c]++; 
            }
        }
    }

    cout<<cnt<<"\n";
    return 0;
}