#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int h, m, n = 45;
    cin>>h>>m;

    while(n){
        m--;
        if(m < 0){
            h--;
            m = 59;
            if(h<0){
                h = 23;
            }else if(h > 23){
                h = 0;
            }
        }
        n--;
    }
    cout<<h<<" "<<m<<"\n";


    return 0;
}