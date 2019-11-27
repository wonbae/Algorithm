#include <bits/stdc++.h>
using namespace std;


int reverse(int a){
    int tmp;
    int rest = a % 10;
    int mid = (a / 10) % 10;
    int share = a / 100;
    tmp = rest * 100 + mid * 10 + share;    

    return tmp;
}

int main(){
    int a,b;
    
    cin>>a>>b;

    int tmp = reverse(a);
    int tmp2 = reverse(b);

    if(tmp > tmp2){
        cout<< tmp;
    }else{
        cout<<tmp2;
    }

    return 0;
}