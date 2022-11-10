#include<iostream>
using namespace std;
#define SIZE 200001

bool isPrime[SIZE];

void eratos(){
    isPrime[0] = true, isPrime[1] = true;

    for(int i = 2; i*i <= SIZE; i++){
        for(int j = i * i; j <= SIZE; j += i){
            if(isPrime[j]) continue;
            isPrime[j] = true;
        }
    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    eratos();

    int N, cnt = 0;
    cin>>N;

    for(int i = 2; i <= N; i++){
        if(!isPrime[i]) cnt++;
    }

    cout<<cnt<<"\n";

    return 0;
}