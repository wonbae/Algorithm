#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double a,b,v;

    cin>>a>>b>>v;

    // double tmp = 0;
    int day = 1;

    // while(1){
    //     tmp += a;

    //     if(tmp >= v){
    //         break;
    //     }

    //     tmp -= b;

    //     day++;

    // }

    day = (v - b - 1) / (a - b ) + 1;
   
    cout<<day<<"\n";


    return 0;
}

