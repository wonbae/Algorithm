#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a,b,c,res;

    cin>>a>>b>>c;

    if(a > b){
        if(a > c){
            if(b > c){
                res = b;
            }else{
                res = c;
            }
        }else{
            if(a > b){
                res = a;
            }else{
                res = b;
            }
        }
    }else{
        if(b > c){
            if(a > c){
                res = a;
            }else{
                res = c;
            }
        }else{
            if(a > b){
                res = a;
            }else{
                res = b;
            }
        }
    }

    cout<<res<<'\n';

    return 0;
}