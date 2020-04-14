#include<bits/stdc++.h>
using namespace std;
#define SIZE 21

int N, A[SIZE][SIZE], district[SIZE][SIZE], ans;
int maxPeople = 0, minPeople = 987654321;

void view(){
    cout<<"\n====== view district =======\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<district[i][j];
        }cout<<"\n";
    }
}
int getSum(int r, int c){
    int pSum = 0;

    for(int i = r; i < N; i++){
        for(int j = c; j < N; j++){
            if(district[i][j] == 5){
                pSum += A[i][j];
            }
        }
    }
    
    return pSum;
}

void gerimendering(int x, int y){
    for(int r = x; r < N; r++){
        for(int c = y; c < N; c++){

        }
    }
}

void setPivot(){
    for(int x = 1; x < N; x++){
        for(int y = 1; y < N; y++){
            for(int d1 = 1; d1 < y; d1++){
                for(int d2 = 1; d2 < N - y; d2++){

                    if(x < x + d1 + d2 && x < x + d1 + d2 <= N){
                        if(y - d1 >= 1 && y - d1 < y && y + d2 > y && y + d2 <= N){
                            gerimendering(x, y);
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>A[i][j];
        }
    }

    setPivot();

    cout<<ans<<"\n";

    return 0;
}