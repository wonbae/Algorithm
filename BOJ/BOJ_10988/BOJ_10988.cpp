#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    bool flag=true;

    cin>>str;
    int strLen = str.length();
    for(int i = 0; i < strLen/2; i++){
        if(str[i] == str[strLen - 1 - i]) continue;
        else{
            flag=false;
            break;
        }
    }
    cout<<flag;
    return 0;
}