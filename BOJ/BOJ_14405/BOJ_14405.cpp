#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    string input;
    bool flag=false;
    cin>>input;

    for(int i = 0; i < input.size(); i++){
        if(i < input.size()-1 && input.substr(i, 2) == "pi" || input.substr(i, 2) == "ka") i+=1;
        else if(i < input.size()-2 && input.substr(i,3) == "chu") i+=2;
        else flag = true;
    }

    if(flag) cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";

    return 0;
}