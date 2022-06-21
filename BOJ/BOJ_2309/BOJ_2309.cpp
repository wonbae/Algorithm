#include<bits/stdc++.h>
using namespace std;
int tall[9];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for(int i = 0; i < 9; i++){
        cin>>tall[i];
    }
    sort(tall, tall+9);
    do{
        int sum = 0;
        for(int i = 0; i < 7; i++) sum+=tall[i];
        if(sum==100) break;
    }while(next_permutation(tall, tall+9));
    for(int i = 0; i < 7; i++){
        cout<<tall[i]<<"\n";
    }
    return 0;
}