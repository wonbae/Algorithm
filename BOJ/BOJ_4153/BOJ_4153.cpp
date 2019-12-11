#include<bits/stdc++.h>
using namespace std;



int main(){
    int a,b,c;

    while(true){
        cin>>a>>b>>c;

        if(a == 0 && b == 0 && c == 0){
            return 0;
        }

        int m = max(max(a,b), c);
        int tmp = 0;

        if(m == a){
            tmp = pow(b,2) + pow(c,2);
        }else if(m == b){
            tmp = pow(a,2) + pow(c,2);
        }else{
            tmp = pow(a,2) + pow(b,2);
        }

        if(pow(m,2) == tmp){
            cout<<"right"<<"\n";
        }
        else{
            cout<<"wrong"<<"\n";
        }
    }


    return 0;
}