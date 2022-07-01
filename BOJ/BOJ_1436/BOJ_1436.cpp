#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    
    int n, i=666;
    cin>>n;

    while(true){
        if(to_string(i).find("666") != string::npos){
            n--;
        }
        if(n==0) break;
        i++;
    }

    cout<<i<<"\n";
    return 0;
}