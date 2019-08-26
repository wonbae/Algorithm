#include <iostream>
using namespace std;

int main(){
    int num, res = 0;
    char ch;

    cin>>num;
    while(num--){
        cin>>ch;
        res += ch - '0';
    }

    cout<<res<<endl;

    return 0;
}