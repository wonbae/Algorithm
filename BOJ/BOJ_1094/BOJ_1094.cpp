#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, stick = 64, res = 0, cnt = 0;
    cin>>x;

    while(x > 0){
        if(stick > x) stick /= 2;
        else{
            cnt++;
            x -= stick;
        }
    }

    cout<<cnt<<"\n";

    return 0;
}