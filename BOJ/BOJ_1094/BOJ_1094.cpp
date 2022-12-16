#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int x, stick=64, cnt=1;
    cin>>x;

    while(x>1){
        if(1 & x) cnt++;
        x/=2;
    }
    cout<<cnt;
    return 0;
}