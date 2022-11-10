#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int a[10], b[10], cnt = 0, awin = 0, bwin = 0, last = 0;

    for(int i = 0; i < 10; i++){
        cin>>a[i];
    }

    for(int i = 0; i < 10; i++){
        cin>>b[i];
    }

    for(int i = 0; i < 10; i++){
        if(a[i] == b[i]){
            awin += 1;
            bwin += 1;
        }else if(a[i] > b[i]){
            awin += 3;
            last = 1;
        }else{
            bwin += 3;
            last = 2;
        }
    }

    if(awin == bwin){
        if(last == 0) cout<<"D";
        if(last == 2){
            cout<<"B";
        }else{
            cout<<"A";
        }
    }
    else{
        if(awin > bwin) cout<<"A"<<"\n";
        else cout<<"B"<<"\n";
    }

    return 0;
}