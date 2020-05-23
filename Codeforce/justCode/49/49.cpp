#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int N, mp[11][11], res = 0;
    int front[11], side[11];

    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>front[i];  //col
    }
    for(int i = 0; i < N; i++){
        cin>>side[i];   //row
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int tmp = min(front[j], side[N - 1 - i]);
            mp[i][j] = tmp;
            res += tmp;
            cout<<tmp<<" ";
        }cout<<endl;
    }

    cout<<res<<"\n";
    return 0;
}