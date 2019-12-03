#include<bits/stdc++.h>
using namespace std;

int main(){
    double n;
    cin>>n;

    double cnt = 1;

    while(1){
        if(n <= 1){
            break;
        }

        n -= 6 * cnt;

        cnt++;

    }

    cout<<cnt<<"\n";

    return 0;

}
