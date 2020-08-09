#include<iostream>
#include<stack>
using namespace std;

void DFS(int a){
    if(a > 7) return ;
    
    // cout<<a; 전위수회
    DFS(a*2);
    // cout<<a; 중위순회
    DFS(a*2+1);
    cout<<a;    //후위순회
    
}

int main(){

    DFS(1);

    return 0;
}