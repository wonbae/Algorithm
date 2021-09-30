#include<iostream>
using namespace std;
int ans = 1;

int main(){
    int a, b;
    cin>>a>>b;

    while(1){
        if(a==b){
            break;
        }
        else if(b%2 != 0 && b%10 != 1){
            ans = -1;
            break;
        }
        else if(a > b){
            ans = -1;
            break;
        }else{
            if(b%2 == 0){
                b/=2;
            }else{
                b/=10;
            }
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}