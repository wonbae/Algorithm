#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int N, arr[101];
    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    int max = arr[N - 1], cnt = 0;
    for(int i = N - 1; i >= 0; i--){
        if(max < arr[i]){
            max = arr[i];
            cnt++;
        }else{
            continue;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}