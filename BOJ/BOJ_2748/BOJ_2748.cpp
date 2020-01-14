#include<bits/stdc++.h>
using namespace std;

long long memorization[10001] = {0,};

long long fib(int n){
    if(n == 0){
        return 0;
    }
    if(n <= 2){
        return 1;
    }

    if(memorization[n] == 0){   //비어있다면, 계산한적이 없으니깐 계산해서 넣어야됨
        memorization[n] = fib(n - 1) + fib(n - 2);
        return memorization[n];
    }else{
        return memorization[n]; //이미 계산해서 가지고 있는 경우
    }

    return fib(n - 1) + fib(n - 2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int num;

    cin>>num;

    cout<<fib(num)<<"\n";

    return 0;
}