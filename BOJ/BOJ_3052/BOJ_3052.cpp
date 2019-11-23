#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[10] = {0,};
    int check[100] = {0,};
    int num = 0, result = 0;

    for(int i = 0; i < 10; i++){
        cin>>num;
        arr[i] = num % 42;
    }

    for(int i = 0; i < 10; i++){
        check[arr[i]] = 1;
    }

    for(int i = 0; i < 100; i++){
        if(check[i] != 0){
            result++;
        }
    }

    cout<<result<<"\n";

    return 0;
}