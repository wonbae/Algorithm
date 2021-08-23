#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;

    if((a+b+c) == 180){
        if(a == 60 && b == 60 && c == 60){
            cout<<"Equilateral";
        }else if(a == b || b == c || a == c){
            cout<<"Isosceles";
        }else{
            cout<<"Scalene";
        }
    }else{
        cout<<"Error";
    }
    return 0;
}