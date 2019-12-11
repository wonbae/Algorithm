#include<bits/stdc++.h>
using namespace std;

int abs(int a, int b){
    return min(a, b - a);
}



int main(){
    int x,y,w,h;

    cin>>x>>y>>w>>h;

    int res = min(abs(x,w), abs(y,h));

    cout<<res<<"\n";


    return 0;
}