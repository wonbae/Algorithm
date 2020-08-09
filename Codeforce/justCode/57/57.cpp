#include<iostream>
#include<stack>
using namespace std;

void recur(int a){
    if(a == 0) return ;
    recur(a / 2);
    cout<<a % 2;
}

int main(){
    int n;
    cin>>n;

    recur(n);

    return 0;
}