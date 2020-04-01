#include<bits/stdc++.h>
using namespace std;

int main(){
    string str[5];

    for(int i = 0; i < 5; i++){
        cin>>str[i];
    }

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            if(i < str[j].size()){
                cout<<str[j][i];
            }
        }
    }
    cout<<"\n";


    return 0;
}