#include<iostream>
using namespace std;

int zeroOne(string s){
    int cnt = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[0] == '0') cnt++;
        if(s[i-1] == '1' && s[i] == '0') cnt++;
    }
    return cnt;
}


int oneZero(string s){
    int cnt = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[0] == '1') cnt++;
        if(s[i-1] == '0' && s[i] == '1') cnt++;
    }
    return cnt;
}

int main(){
    string str;
    cin>>str;
    int ans = min(zeroOne(str), oneZero(str));
    cout<<ans<<"\n";
    return 0;
}