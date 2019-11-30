#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a,b,c,x;
    cin>>a>>b>>c;

    if(b>=c){
        cout<<-1<<"\n";
    }else{
        x = a / (c - b) + 1;
        cout<<x<<"\n";
    }

    

    return 0;
}