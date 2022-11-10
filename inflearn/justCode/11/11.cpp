#include<iostream>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);

    int N, tmp = 0, cnt = 0;

    cin>>N;
    
    for(int i = 1; i <= N; i++){
        tmp = i;
        while(tmp > 0){
            tmp /= 10;
            cnt++;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}