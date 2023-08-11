#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0;
    string bits;
    cin>>n>>bits;

    for(auto i : bits){
        ans += i == '1';
    }
    cout<<ans;

    return 0;
}