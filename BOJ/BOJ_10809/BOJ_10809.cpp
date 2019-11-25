#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int alphabet[26];
    memset(alphabet, -1, sizeof(alphabet));

    cin>>str;

    int len = str.length();

    for(int i = 0; i < len; i++){
        int idx = str[i] - 97;
        // cout<<"idx : "<<idx<<"\n";
        if(alphabet[idx] == -1){
            alphabet[idx] = i;
        }else{
            continue;
        }
        
    }

    for(int i = 0; i < 26; i++){
        cout<<alphabet[i]<<" ";
    }

    return 0;
}