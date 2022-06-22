#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin>>n;
    string pat;
    cin>>pat;

    int pos = pat.find('*');
    string pre = pat.substr(0, pos);
    string suf = pat.substr(pos+1);
    string str;

    while(n--){
        cin>>str;
        if(pre.size() + suf.size() > str.size()) cout<<"NE\n";
        else{
            if(pre == str.substr(0, pre.size()) && suf == str.substr(str.size()-suf.size())){
                cout<<"DA\n";
            }else{
                cout<<"NE\n";
            }
        }
    }
    return 0;
}