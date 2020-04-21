#include<bits/stdc++.h>
using namespace std;
#define SIZE 13

int a[SIZE];
int check[SIZE];
int N;

void nCr(int index, int cnt){
    if(cnt == 6){
        for(int i = 0; i < 6; i++){
            cout<<check[i]<<" ";
        }cout<<"\n";

        return ;
    }

    for(int i = index; i < N; i++){
        check[cnt] = a[i];
        nCr(i + 1, cnt + 1);
    }
}

int main(){
    while(1){
        cin>>N;
        if(N == 0) break;
        for(int i = 0; i < N; i++){
            cin>>a[i];
        }

        nCr(0, 0);
        cout<<"\n";
    }
    return 0;
}