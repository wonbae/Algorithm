#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < i + 1; j++){
            cout<<"*";
        }
        for(int k = (N - 1 - i) * 2 ; k > 0; k--){
            cout<<" ";
        }
        for(int l = 0; l < i + 1; l++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int n = 0; n < N - 1; n++){
        for(int m = N - n - 1; m > 0; m--){
            cout<<"*";
        }
        for(int k = 0; k < (n + 1)*2; k++){
            cout<<" ";
        }
        for(int l = N - n - 1; l > 0; l --){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}