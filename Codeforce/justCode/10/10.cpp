#include<iostream>
using namespace std;

int digit_sum(int x){
    int sum = 0, tmp = x;

    while(1){
        if(tmp <= 0) break;
        sum += tmp % 10;
        tmp /= 10;
    }

    return sum;
}

int main(){
    freopen("input.txt", "rt", stdin);
    int N,a,res = 0, num = 0;
    cin>>N;
    while(N--){
        cin>>a;
        int tmp = digit_sum(a);
        if(tmp > res){
            res = tmp;
            num = a;
        }else if(tmp == res){
            if(a > num){
                num = a;
            }
        }
    }

    cout<<num<<"\n";

    return 0;
}