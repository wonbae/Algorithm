#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int N, a[101] = {0,}, b[101] = {0,};
    cin>>N;

    for(int i = 0; i < N; i++){
        cin>>a[i];
    }

    for(int i = 0; i < N; i++){
        cin>>b[i];
    }

    for(int i = 0; i < N; i++){
        if(a[i] == b[i]){
            cout<<"D"<<"\n";
        }else if(a[i] == 1 && b[i] == 2){
            cout<<"B"<<"\n";
        }else if(a[i] == 2 && b[i] == 3){
            cout<<"B"<<"\n";
        }else if(a[i] == 3 && b[i] == 1){
            cout<<"B"<<"\n";
        }else{
            cout<<"A"<<"\n";
        }
    }

    return 0;
}