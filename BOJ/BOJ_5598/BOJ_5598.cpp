#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    string result;

    cin>>str;

    int len = str.length();
    
    for(int i = 0; i < len; i++){
        int idx = (str[i] - 'A' - 3 + 26) % 26;
        result += idx + 'A';
    }
    
    cout<<result<<"\n";

    return 0;
}