#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int alphabet[26] = {0,};

    cin>>str;
    int len = str.length();

    for(int i = 0; i < len; i++){
        if(str[i] - 'a' >= 0 && str[i] - 'a' <= 26){
            int idx = str[i] - 'a';
            alphabet[idx]++;
        }else if(str[i] - 'A' >= 0 && str[i] - 'A' <= 26){
            int idx = str[i] - 'A';
            alphabet[idx]++;
        }
    }

    // for(int i = 0; i < 26; i++){
    //     cout<<alphabet[i]<<" ";
    // }

    int max_idx = 0;
    int max = 0;

    for(int i = 0; i < 26; i++){

        if(max < alphabet[i]){

            max = alphabet[i];
            max_idx = i;
        }
    }
    
    int count = 0;
    for(int i = 0; i < 26; i++){
        if(max == alphabet[i]){
            count++;
            if(count >= 2){
                cout<<"?";
                break;
            }
        }
    }

    // cout<<max<<" "<<max_idx<<"\n";
    if(count == 1){
        char b = max_idx + 'A';
        cout<<b<<"\n";
    }
    

    return 0;
}