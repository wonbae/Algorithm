#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a, b;
    cin>>a>>b;
    if(a > b){
        int tmp = gcd(a,b);
        cout<<tmp*(a/tmp)*(b/tmp)<<"\n";
    }else{
        int tmp = gcd(b,a);
        cout<<tmp*(a/tmp)*(b/tmp)<<"\n";
    }
    return 0;
}