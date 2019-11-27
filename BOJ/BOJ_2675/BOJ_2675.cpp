#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;

    cin>>T;

    int n;
    string str;
    string result;

    for(int i = 0; i < T; i++){
        cin>>n;
        cin>>str;

        int len = str.length();

        for(int j = 0; j < len; j++){
            for(int k = 0; k < n; k++){
                result += str[j];
            }
        }
        
        cout<<result<<"\n";
        result = "";
    }

    

    return 0;
}