#include<iostream>
#include<algorithm>
using namespace std;

string ans[100];

int main(){
    string str;    
    cin>>str;
    int len = str.length();
    string ans[len];
    
    for(int i = 0; i < str.length(); i++){
        string tmp = "";
        for(int j = i; j < str.length(); j++){
            tmp += str[j];
        }
        ans[i] = tmp;
    }

    sort(ans, ans + len);

    for(int i = 0; i < len; i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}