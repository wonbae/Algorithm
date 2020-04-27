#include<iostream>
using namespace std;

// int main(){
//     int N, cnt;
//     cin>>N;

//     //3만 이상부터는 1초넘게 걸림... 
//     for(int i = 1; i <= N; i++){
//         cnt = 0;
//         for(int j = 1; j <= i; j++){
//             if(i % j == 0) cnt++;
//         }
//         cout<<cnt<<" ";
//     }cout<<"\n";

//     return 0;
// }

int cnt[50001];

int main(){
    int N;
    cin>>N;

    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j+=i){       //eratos 처럼 배수를 처리하면 됨
            cnt[j] += 1;
        }
    }

    for(int i = 1; i <= N; i++){
        if(cnt[i] != 0) cout<<cnt[i]<<" ";
    }

    return 0;
}