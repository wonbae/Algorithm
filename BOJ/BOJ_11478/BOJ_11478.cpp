// Need to Improve!
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
int main(){
    fastio;

    string str;
    cin>>str;

    set<string> subset;

    for(int i = 0; i < str.size(); i++){
        string tmp = "";
        for(int j = i; j < str.size(); j++){
            tmp += str[j];
            // cout<<tmp<<"\n";
            subset.insert(tmp);
        }
    }

    cout<<subset.size();
    return 0;
}
