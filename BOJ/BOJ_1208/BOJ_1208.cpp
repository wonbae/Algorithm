#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, S, ans = 0;
    cin>>N>>S;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin>>v[i];
    }

    int lt = 0, rt = N-1;
    while(true){
        if(S == ans) break;
        for(int i = lt; i <= rt; i++){
            ans+=v[i];
        }
        if(ans < S){
            lt++;
        }else if(ans > S){
            rt--;
        }
    }


    return 0;
}