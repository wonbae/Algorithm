#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    long long ans = 0;
    cin>>n;

    string input;
    cin>>input;

    string tmp;

    for(int i = 0; i < n; i++){
        if(input[i] >= '0' && input[i] <= '9'){
            tmp+=input[i];
        }else{
            if(!tmp.empty()){
                ans += stoi(tmp);
                tmp.clear();
            }            
        }
    }

    if(!tmp.empty()){
        ans+=stoi(tmp);
        tmp.clear();
    }
    cout<<ans;
    return 0;
}