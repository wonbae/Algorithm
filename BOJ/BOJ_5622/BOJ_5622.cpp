#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin>>input;
    
    int dial[27] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
    int len = input.length();
    int result = 0;

    for(int i = 0; i < len; i++){
        int idx = input[i] - 'A' ;
        result += dial[idx];
    }

    cout<<result;


    return 0;
}