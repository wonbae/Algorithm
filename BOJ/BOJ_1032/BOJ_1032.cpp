#include<bits/stdc++.h>
using namespace std;
#define SIZE 53

int main(){
    string str[SIZE];
    string res;
    bool flag = false;
    int N;
    cin>>N;

    if(N == 1){
        string tmp;
        cin>>tmp;
        cout<<tmp<<"\n";
        return 0;
    }else{
        for(int i = 0; i < N; i++){
            cin>>str[i];
        }
    }

    int len = str[0].length();

    for(int i = 0; i < len; i++){
        for(int j = 0; j < N - 1; j++){
            if(str[j][i] == str[j + 1][i]){
                flag = true;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            res += str[0][i];
        }else{
            res += '?';
        }
    }
    
    cout<<res<<"\n";

    return 0;
}