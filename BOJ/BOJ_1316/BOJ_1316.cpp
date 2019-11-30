#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    string input;
    
    int count = 0;

    for(int i = 0; i < T; i++){
        // count = 0;
        bool alphabet[26];
        bool flag = true;

        cin>>input;

        int len = input.length();

        memset(alphabet, true, sizeof(alphabet));

        for(int j = 0; j < len - 1; j++){
            if(input[j] == input[j + 1]){
                continue;
            }else{
                int idx = input[j] - 'a';
                int idx2 = input[j + 1] - 'a';

                // cout<<"idx : "<< idx<<", idx2 : "<<idx2<<"\n";

                if(alphabet[idx] && alphabet[idx2]){
                    alphabet[idx] = false;
                }else{
                    flag = false;
                    // break;
                }
            }
        }

        if(flag){
            count++;
        }

    }
     cout<<count<<"\n";

    return 0;
}