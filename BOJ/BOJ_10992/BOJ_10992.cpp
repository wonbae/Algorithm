#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    for(int i = 0; i < N; i++){
        for(int k = 0; k < N - i - 1; k++){
            cout<<" ";
        }cout<<"*";
        if(i == N - 1){
            for(int l = 0; l < i * 2; l++){
                cout<<"*";
            }
        }else if(i){
            for(int j = 0; j < i * 2 - 1; j++){
                cout<<" ";
            }cout<<"*";
        }
        
        cout<<endl;
    }

    return 0;
}