#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int c = 0, h = 0, pos, res = 0, i;
    string a;
    cin>>a;

    if(a[1] == 'H'){
        pos = 1;
        c = 1;
    }else{
        
        for(i = 1; a[i] != 'H'; i++){
            c = c * 10 + (a[i] - 48);
        }
        pos = i;
    }

    
    if(a[pos + 1] == '\n') h = 1;
    else{
        for(i = pos + 1; i < a.length(); i++){
            h = h * 10 + (a[i] - 48);
        }
    }

    res = c * 12 + h;

    cout<<res<<"\n";

    return 0;
}