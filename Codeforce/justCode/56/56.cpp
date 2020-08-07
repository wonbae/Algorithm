#include<iostream>
using namespace std;

void recur(int a){
    if(a == 0) return ;
    recur(a - 1);
    cout<<a<<" ";
}

int main(){
    int n;
    cin>>n;
    recur(n);
}