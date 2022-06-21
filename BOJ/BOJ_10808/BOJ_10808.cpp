#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string str;
    cin>>str;
    int alph[26]={0,};

    for(int i = 0; i < str.length(); i++){
        alph[str[i]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        cout<<alph[i]<<" ";
    }

    return 0;
}