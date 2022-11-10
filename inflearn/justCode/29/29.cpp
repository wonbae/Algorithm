//input : 15, result : 2
#include<iostream>
using namespace std;

int main(){
    int n, cnt = 0, digit = 0;
    cin>>n;

    for(int i = 1; i <= n; i++){
        if(i < 10){
            if(i == 3) cnt++;
        }else{
            int tmp = i;
            while(tmp > 0){
                digit = tmp % 10;
                if(digit == 3) cnt++;
                tmp /= 10;
            }
        }
    }  

    cout<<cnt<<"\n";

    return 0;
}