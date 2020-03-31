#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, car, res = 0;
    cin>>n;

    for(int i = 0; i < 5; i++){
        cin>>car;
        if(n == car) res++;
    }

    cout<<res<<"\n";

    return 0;
}