#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int num=1, cnt=1;
        while(true){
            if(num%n==0){
                printf("%d\n",cnt);
                break;
            }else{
                num = (num*10)+1;
                num %= n;
                cnt+=1;
            }
        }
    }

    return 0;
}