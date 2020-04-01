#include<bits/stdc++.h>
using namespace std;

bool arr[10001];

int d(int n){
    int sum = n;

    while(1){
        if(n == 0) break;
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

int main(){

    for(int i = 1; i < 10001; i++){
        int idx = d(i);

        if(idx <= 10001){
            arr[idx] = true;
        }
    }

    for(int i = 1; i < 10001; i++){
        if(!arr[i]) cout<<i<<"\n";
    }
    
    return 0;
}