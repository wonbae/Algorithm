#include<iostream>
using namespace std;

int main(){
    int n, pivot, left, right, res = 0, k = 3, d = 1;
    cin>>n;

    while(left != 0){
        pivot = (n / d) % 10;
        left = n / (d * 10);
        right = n % d;

        if(pivot > k){
            res += (left + 1) * d;
        }else if(pivot == k){
            res += (left * d) + right + 1;
        }else{
            res += left * d;
        }

        d *= 10;
    }

    cout<<res<<"\n";

    return 0;
}