#include<bits/stdc++.h>
using namespace std;

string str, tmp;
vector<string> v;

void delstr(){
    if(tmp.size()){
        while(true){
            if(tmp.size() && tmp.front() == '0'){
                tmp.erase(tmp.begin());
            } 
            else break;
        }
        if(tmp.size() == 0) tmp = "0";
        v.push_back(tmp);
        tmp = "";
    }
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        tmp="";
        cin>>str;
        for(int i = 0; i < str.size(); i++){
            if(str[i] < 58) tmp += str[i];
            else{
                delstr();
            }
        }
        delstr();
    }

    sort(v.begin(), v.end(), cmp);

    for(string s : v){
        cout<<s<<"\n";
    }

    return 0;
}