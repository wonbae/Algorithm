#include<iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    freopen("input.txt","rt",stdin);
    int N, M, time = 0, res = -2147000000;
    int a[100] = {0,};
    
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        cin>>a[i];
        if(a[i] > M) time++;
        else time = 0;

        res = max(res, time);
    }

    if(res == 0) cout<<-1;
    else cout<<res<<"\n";
    

    return 0;
}