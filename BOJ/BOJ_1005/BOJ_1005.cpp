#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int T, K, N, X, Y, end;;
    cin>>T;
    while(T--){
        cin>>N>>K;
        vector<int> time(N+1);
        vector<int> degree(N+1);
        vector<int> building[1001];

        for(int i = 1; i <= N; i++){
            cin>>time[i];
        }

        for(int i = 0; i < K; i++){
            cin>>X>>Y;
            building[X].push_back(Y);
            degree[Y]++;
        }
        cin>>end;

        queue<int> q;
        
        

    }

    return 0;
}