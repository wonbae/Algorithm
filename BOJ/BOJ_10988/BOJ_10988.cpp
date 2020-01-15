#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string input;
    bool flag = true;

    cin>>input;

    int len = input.length();
    int mid = len/2;

    if(mid % 2 == 0){  //even
        for(int i = 0; i <= mid - 1; i++){
            if(input[i] == input[len - 1 - i]){
                flag = true;
            }else{
                flag = false;
                cout<<flag;
                return 0;
            }
        }
    }
    else{           //odd
        for(int i = 0; i < mid; i++){
            if(input[i] == input[len - 1 - i]){
                flag = true;
            }else{
                flag = false;
                cout<<flag;
                return 0;
            }
        }
    }
    

    cout<<flag<<"\n";

    return 0;
}